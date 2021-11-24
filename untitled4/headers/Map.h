#ifndef UNTITLED4_MAP_H
#define UNTITLED4_MAP_H
#include "Tile.h"

static const int FIELD_HEIGHT = 10;
static const int FIELD_WIDTH = 10;

static int MAP[FIELD_HEIGHT][FIELD_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 1, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 1, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 1, 0},
        {0, 3, 2, 2, 2, 2, 2, 2, 4, 0},
};
//TODO сделать генерацию уровней


/*
3 - cell of start
4 - cell of finish
2 - cell where player can build buildings
1 - cell where enemies can move
 all the enemies strive to cell with number 4
 */

#endif //UNTITLED4_MAP_H
