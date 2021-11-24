#include <iostream>
#include "../headers/GameField.h"

bool GameField::IsTilePassable(const Coordinate &coord) const {
    if (coord.x < 0 || coord.x >= FIELD_WIDTH || coord.y < 0 || coord.y >= FIELD_HEIGHT)
        return false;
    return GetTileAt(coord).IsOpen();
}

bool GameField::IsTileBuildable(const Coordinate &coord) const {
    if (coord.x < 0 || coord.x >= FIELD_WIDTH || coord.y < 0 || coord.y >= FIELD_HEIGHT)
        return false;
    return GetTileAt(coord).IsBuildable();
}

void GameField::InitField() {
    GenerateMap();
    Animation staticAnimation(0, 0, 0.0f, 0.0f);
    field = new Tile * [FIELD_HEIGHT];
    for(int i=0; i<FIELD_HEIGHT; i++){
        field[i] = new Tile[FIELD_WIDTH];
    }

    for(GameField::Iterator iter = Begin(); iter != End(); iter ++){
        iter.GetTile().tileType = MAP[iter.coordinates.y][iter.coordinates.x];
        if(iter.GetTile().tileType == TR_GRASS){
            Animation grass(0, 2, 1.0f, 0.1f);
            iter.GetTile().GetTile().SetAnimation(grass);
        }
        else
            iter.GetTile().GetTile().SetAnimation(staticAnimation);
    }
}

GameField::~GameField() {
    for(int i=0; i< FIELD_HEIGHT; i++){
        delete[] field[i];
    }
    delete[] field;
}

// Checking all direction recursively
void GameField::FindPath(std::map<int, Coordinate> & currentPath, GameField::Iterator & iter){
    if (IsTileFinish(iter.coordinates))
        return;
    Coordinate coordUp(iter.coordinates.x, iter.coordinates.y - 1);
    Coordinate coordDown(iter.coordinates.x, iter.coordinates.y + 1);
    Coordinate coordLeft(iter.coordinates.x - 1, iter.coordinates.y);
    Coordinate coordRight(iter.coordinates.x + 1, iter.coordinates.y);
    Coordinate coordUpLeft(iter.coordinates.x - 1, iter.coordinates.y - 1);
    Coordinate coordDownLeft(iter.coordinates.x + 1, iter.coordinates.y - 1);
    Coordinate coordUpRight(iter.coordinates.x - 1, iter.coordinates.y + 1);
    Coordinate coordDownRight(iter.coordinates.x + 1, iter.coordinates.y + 1);
    Coordinate coordArr[8] = {coordUp, coordDown, coordLeft, coordRight, coordUpLeft, coordUpRight, coordDownLeft, coordDownRight};
    for(auto coordinate: coordArr){
        auto resultFind = std::find_if(currentPath.begin(), currentPath.end(), [coordinate](const auto& item){return item.second == coordinate;});
        if (resultFind == currentPath.end() && (IsTilePassable(coordinate) || IsTileFinish(coordinate))){
            resultFind --;
            int newNumberStep = resultFind->first + 1;
            currentPath[newNumberStep] = coordinate;
            iter.coordinates = coordinate;
            FindPath(currentPath, iter);
            return;
        }
    }
}

std::map<int, Coordinate> * GameField::ComputeEnemiesPath() {
    auto path = new std::map<int, Coordinate>;
    for(Iterator iterator = Begin(); iterator != End(); iterator++){
            if(iterator.GetTile().IsStart()){
                (*path)[0] = iterator.coordinates;
                FindPath(*path, iterator);
                break;
            }
        }
    return path;
}

bool GameField::IsTileFinish(const Coordinate &coord) const {
    if (coord.x < 0 || coord.x >= FIELD_WIDTH || coord.y < 0 || coord.y >= FIELD_HEIGHT)
        return false;
    return GetTileAt(coord).IsFinish();
}

void GameField::SetBusy(bool newBusyStatus, const Coordinate &coord) const {
    if (coord.x < 0 || coord.x > FIELD_WIDTH || coord.y < 0 || coord.y > FIELD_HEIGHT)
        std::cout<<"coordinate out of range\n";
    else
        GetTileAt(coord).busy = newBusyStatus;
}

void GameField::GenerateMap() {
    Coordinate start;
    Coordinate finish(0, FIELD_HEIGHT-1);
    Coordinate firstStopPoint;
    Coordinate secondStopPoint;
    srand(time(NULL));
    while (start == finish || start == firstStopPoint || start == secondStopPoint || secondStopPoint == firstStopPoint ||
           finish==secondStopPoint || finish==firstStopPoint || firstStopPoint.y >= secondStopPoint.y){
        start.x = rand()%FIELD_WIDTH;
        start.x = rand()%FIELD_WIDTH;
        finish.x = rand()%FIELD_WIDTH;
        firstStopPoint.x = rand()%(FIELD_WIDTH-1) + 1;
        firstStopPoint.y = rand()%(FIELD_HEIGHT - 2) + 1;
        secondStopPoint.y = rand()%(FIELD_WIDTH - 1) + 1;
        secondStopPoint.x = firstStopPoint.x;
    }
    std::vector<Coordinate> path;
    GeneratePathBetweenPoints(start, firstStopPoint, path);
    GeneratePathBetweenPoints(firstStopPoint, secondStopPoint, path);
    GeneratePathBetweenPoints(secondStopPoint, finish, path);
    for(int i = 0; i<FIELD_HEIGHT; i++ ){
        for(int j=0; j<FIELD_WIDTH; j++){
            auto findTrail = [i, j](Coordinate point){return (point == Coordinate(i, j) || point == Coordinate(i - 1, j)) ;};
            auto findPlain = [i, j](Coordinate point){return point == Coordinate(i + 1, j) || point == Coordinate(i - 3, j) ||
                                                             point == Coordinate(i-2, j) || point == Coordinate(i + 2, j);};
            auto resulFindTrail = find_if(path.begin(), path.end(), findTrail);
            auto resulFindPlain = find_if(path.begin(), path.end(), findPlain);
            if(resulFindTrail != path.end()){
                MAP[i][j] = 1;
            }
            else if(resulFindPlain != path.end()){
                MAP[i][j] = 2;
            }
            else
                MAP[i][j] = 0;
        }
    }
    MAP[start.x][start.y] = 3;
    MAP[finish.x][finish.y] = 4;
//    for(int i=0; i<FIELD_HEIGHT; i++){
//        for(int j=0; j<FIELD_WIDTH; j++){
//            std::cout<<MAP[i][j]<<" ";
//        }
//        std::cout<<std::endl;
//    }
}

void GameField::GeneratePathBetweenPoints(Coordinate point1, Coordinate point2, std::vector<Coordinate> &path) {
    int x1 = point1.x;
    int y1= point1.y;
    int x2 = point2.x;
    int y2 = point2.y;
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    path.emplace_back(x2, y2);
    while(x1 != x2 || y1 != y2)
    {
        path.emplace_back(x1, y1);
        int error2 = error * 2;
        if(error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }
}

bool operator!=(const GameField::Iterator& first, const GameField::Iterator& second) {
    return first.firstElement + first.coordinates.y != second.firstElement;
}

bool operator==(const GameField::Iterator& first, const GameField::Iterator& second) {
    return first.firstElement + first.coordinates.x == second.firstElement + second.coordinates.x;
}

Tile & GameField::Iterator::operator++(int) {
    if (firstElement + coordinates.y != firstElement + FIELD_HEIGHT and
    *firstElement + coordinates.x != *firstElement + FIELD_WIDTH - 1){
        coordinates.x += 1;
    }
    else if (firstElement + coordinates.y != firstElement + FIELD_HEIGHT and
    *firstElement + coordinates.x == *firstElement + FIELD_WIDTH - 1){
        coordinates.x = 0;
        coordinates.y += 1;
    }
    return *(*(firstElement+coordinates.y)+coordinates.x);
}
