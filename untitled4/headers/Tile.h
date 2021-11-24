#ifndef UNTITLED4_TILE_H
#define UNTITLED4_TILE_H
#include "AnimationSprite.h"
#include <memory>

enum TileRes{
    TR_GRASS,
    TR_TRAIL,
    TR_PLAIN,
    TR_START,
    TR_FINISH
};


class Tile{
public:
    int tileType;
    AnimationSprite & GetTile(){
        return sprite;
    }
    bool busy = false;
    Tile()= default;
    bool IsOpen() const {
        return tileType == TR_TRAIL;
    }
    bool IsBuildable() const {
        return tileType == TR_PLAIN && !busy;
    }
    bool IsFinish() const{
        return tileType == TR_FINISH;
    }
    bool IsStart() const{
        return tileType == TR_START;
    }

private:
    AnimationSprite sprite;
};

#endif //UNTITLED4_TILE_H
