#ifndef UNTITLED4_PLAYER_H
#define UNTITLED4_PLAYER_H
#include "GameObject.h"

class Player:public GameObject{
public:
    Player(sf::Texture & texture, Animation & animation, Coordinate & newPosition): GameObject(texture, animation, newPosition){
        health = 1000;
        damage = 0;
    }
};

#endif //UNTITLED4_PLAYER_H
