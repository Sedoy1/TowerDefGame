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

        const Tile & GetTileAt(const Coordinate & cord) const {
            assert(cord.x >= 0 && cord.x < FIELD_WIDTH);
            assert(cord.y >= 0 && cord.y < FIELD_HEIGHT);
            return field[cord.y][cord.x];
        }

        Tile & GetTileAt(const Coordinate & cord) {
            assert(cord.x >= 0 && cord.x < FIELD_WIDTH);
            assert(cord.y >= 0 && cord.y < FIELD_HEIGHT);
            return field[cord.y][cord.x];
        }
        Iterator Begin() const{  return field;}
        Iterator End() const{ return  field + FIELD_HEIGHT;}
        bool IsTilePassable(const Coordinate &coord) const;
        bool IsTileBuildable(const Coordinate &coord) const;
        bool IsTileFinish(const Coordinate &coord) const;
        void InitField();
        // recursion function for find path
        void FindPath(std::map<int, Coordinate> & currentPath, GameField::Iterator & iter);
        std::map<int, Coordinate> * ComputeEnemiesPath();
        ~GameField();
        Tile ** field;
};

bool operator == (const GameField::Iterator& first, const GameField::Iterator& second);
bool operator != (const GameField::Iterator& first, const GameField::Iterator& second);
#endif //UNTITLED4_GAMEFIELD_H