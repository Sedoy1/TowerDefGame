#ifndef UNTITLED4_CANNON_H
#define UNTITLED4_CANNON_H

#include "FriendObject.h"
#include "Coordinate.h"

class Cannon: public FriendObject{
public:
    Cannon(sf::Texture  & newTexture, std::vector<std::shared_ptr<Enemy>> & enemyVector, Coordinate & newPosition){
        aSprite.InitSprite(newTexture, newPosition, 42, 38);
        Animation newAnimation(0, 1, 0.2f, 0.1f);
        aSprite.SetAnimation(newAnimation);
        damage = 0;
        range = 10;
        shootDelay = 10.0f;
        this->enemyVector = &enemyVector;
    }
};

#endif //UNTITLED4_CANNON_H
