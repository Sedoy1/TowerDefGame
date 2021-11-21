#ifndef UNTITLED4_PLAYER_H
#define UNTITLED4_PLAYER_H
#include "GameObject.h"

class Player:public GameObject{
public:
    Player(sf::Texture & texture, Coordinate & newPosition){
        aSprite.InitSprite(texture, newPosition);
        Animation newAnimation(0, 2, 1.0f, 0.2f);
        aSprite.SetAnimation(newAnimation);
        health = 100;
        damage = 0;
    }
};

#endif //UNTITLED4_PLAYER_H
