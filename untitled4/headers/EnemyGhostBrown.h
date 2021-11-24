#ifndef UNTITLED4_ENEMYGHOSTBROWN_H
#define UNTITLED4_ENEMYGHOSTBROWN_H

#include "Enemy.h"

class EnemyGhostBrown : public Enemy{
public:
    EnemyGhostBrown(sf::Texture & texture, Coordinate & startPosition){
        aSprite.InitSprite(texture, startPosition, 50, 50);
        Animation newAnimation(0, 2, 1.0f, 0.2f);
        aSprite.SetAnimation(newAnimation);
        health = 5;
        damage = 7;
        speed = 7;
    }
};

#endif //UNTITLED4_ENEMYGHOSTBROWN_H
