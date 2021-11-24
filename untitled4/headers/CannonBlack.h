#ifndef UNTITLED4_CANNONBLACK_H
#define UNTITLED4_CANNONBLACK_H

#include "FriendObject.h"

class CannonBlack: public FriendObject{
public:
    CannonBlack(sf::Texture  & newTexture, std::vector<std::shared_ptr<Enemy>> & enemyVector, Coordinate & newPosition){
        aSprite.InitSprite(newTexture, newPosition, 42, 38);
        Animation newAnimation(0, 4, 0.2f, 0.1f);
        aSprite.SetAnimation(newAnimation);
        damage = 2;
        range = 10;
        shootDelay = 20.0f;
        this->enemyVector = &enemyVector;
    }
};


#endif //UNTITLED4_CANNONBLACK_H
