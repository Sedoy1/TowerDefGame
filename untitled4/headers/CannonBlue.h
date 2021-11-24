#ifndef UNTITLED4_CANNONBLUE_H
#define UNTITLED4_CANNONBLUE_H

#include "FriendObject.h"
#include "Coordinate.h"

class CannonBlue: public FriendObject{
public:
    CannonBlue(sf::Texture  & newTexture, std::vector<std::shared_ptr<Enemy>> & enemyVector, Coordinate & newPosition){
        aSprite.InitSprite(newTexture, newPosition, 42, 38);
        Animation newAnimation(0, 4, 0.2f, 0.1f);
        aSprite.SetAnimation(newAnimation);
        damage = 0;
        range = 10;
        shootDelay = 10.0f;
        this->enemyVector = &enemyVector;
    }
};

#endif //UNTITLED4_CANNONBLUE_H
