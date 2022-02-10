#ifndef UNTITLED4_ENEMYGHOSTBLACK_H
#define UNTITLED4_ENEMYGHOSTBLACK_H
#include "Enemy.h"

class EnemyGhostBlack : public Enemy{
    public:
        EnemyGhostBlack(sf::Texture & texture, Coordinate & startPosition){
            aSprite.InitSprite(texture, startPosition, 50, 50);
            Animation newAnimation(0, 2, 1.0f, 0.2f);
            aSprite.SetAnimation(newAnimation);
            health = 10;
            damage = 10;
            speed = 2;
            typeObject = GhostBlack;
        }
};


#endif //UNTITLED4_ENEMYGHOSTBLACK_H
