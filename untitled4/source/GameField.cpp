#include <iostream>
#include "../headers/GameField.h"

bool GameField::IsTilePassable(const Coordinate &coord) const {
    if (coord.x < 0 || coord.x > FIELD_WIDTH || coord.y < 0 || coord.y > FIELD_HEIGHT)
        return false;
    return GetTileAt(coord).IsOpen();
}

bool GameField::IsTileBuildable(const Coordinate &coord) const {
    if (coord.x < 0 || coord.x > FIELD_WIDTH || coord.y < 0 || coord.y > FIELD_HEIGHT)
        return false;
    return GetTileAt(coord).IsBuildable();
}

void GameField::InitField() {
    Animation staticAnimation(0, 0, 0.0f, 0.0f);
    field = new Tile * [FIELD_HEIGHT];
    for(int i=0; i<FIELD_HEIGHT; i++){
        field[i] = new Tile[FIELD_WIDTH];
    }

    for(GameField::Iterator iter = Begin(); iter != End(); iter ++){
        iter.GetTile().tileType = MAP[iter.coordinates.y][iter.coordinates.x];
        if(iter.GetTile().tileType == TR_GRASS){
            Animation grass(0, 2, 1.0f, 0.1f);
            iter.GetTile().sprite.SetAnimation(grass);
        }
        else
            iter.GetTile().sprite.SetAnimation(staticAnimation);
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
    Coordinate coordArr[4] = {coordUp, coordDown, coordLeft, coordRight};
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
    if (coord.x < 0 || coord.x > FIELD_WIDTH || coord.y < 0 || coord.y > FIELD_HEIGHT)
        return false;
    return GetTileAt(coord).IsFinish();
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
