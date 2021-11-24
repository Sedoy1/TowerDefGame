#ifndef UNTITLED4_CANNONORANGE_H
#define UNTITLED4_CANNONORANGE_H

#include "FriendObject.h"
#include "Coordinate.h"

class CannonOrange: public FriendObject{
public:
    CannonOrange(sf::Texture  & newTexture, std::vector<std::shared_ptr<Enemy>> & enemyVector, Coordinate & newPosition){
        aSprite.InitSprite(newTexture, newPosition, 40, 38);
        Animation newAnimation(0, 4, 0.2f, 0.1f);
        aSprite.SetAnimation(newAnimation);
        damage = 1;
        range = 10;
        shootDelay = 5.0f;
        this->enemyVector = &enemyVector;
    }
};


#endif //UNTITLED4_CANNONORANGE_H
