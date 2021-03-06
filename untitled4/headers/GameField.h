#ifndef UNTITLED4_GAMEFIELD_H
#define UNTITLED4_GAMEFIELD_H
#include "Tile.h"
#include "Map.h"
#include "Coordinate.h"
#include <cassert>
#include "iostream"

class GameField: public Tile{
    public:
    //custom iter for Tile matrix
    struct Iterator{
        Coordinate coordinates;
        Tile ** const firstElement;
        Iterator(Tile ** first): firstElement(first), coordinates(0, 0){}
        Tile & operator ++ (int);
        Tile & GetTile(){ return firstElement[coordinates.y][coordinates.x];}
    };

    Iterator Begin() const{  return field;}
    Iterator End() const{ return  field + FIELD_HEIGHT;}
    GameField();
    GameField(GameField && other);
    GameField(const GameField & other);
    ~GameField();
    bool IsTilePassable(const Coordinate &coord) const;
    bool IsTileBuildable(const Coordinate &coord) const;
    bool IsTileFinish(const Coordinate &coord) const;
    void InitField();
    void SetBusy(bool newBusyStatus, const Coordinate & coord) const;
    void GenerateMap();
    void ReloadField();
    // recursion function for find path
    void FindPath(std::map<int, Coordinate> & currentPath, GameField::Iterator & iter);
    std::map<int, Coordinate> * ComputeEnemiesPath();
    Tile & GetTileAt(const Coordinate & cord) const;
    void SetMap(const Coordinate & cord, int newType);
    Tile ** field{};

private:
    void GeneratePathBetweenPoints(Coordinate point1, Coordinate point2, std::vector<Coordinate> &path);
    int MAP[FIELD_HEIGHT][FIELD_WIDTH] = {0};
};

bool operator == (const GameField::Iterator& first, const GameField::Iterator& second);
bool operator != (const GameField::Iterator& first, const GameField::Iterator& second);
#endif //UNTITLED4_GAMEFIELD_H
