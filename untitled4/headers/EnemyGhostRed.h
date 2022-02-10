#ifndef UNTITLED4_ENEMYGHOSTRED_H
#define UNTITLED4_ENEMYGHOSTRED_H
#include "Enemy.h"

class EnemyGhostRed : public Enemy{
public:
    EnemyGhostRed(sf::Texture & texture, Coordinate & startPosition){
        aSprite.InitSprite(texture, startPosition, 50, 50);
        Animation newAnimation(0, 2, 1.0f, 0.2f);
        aSprite.SetAnimation(newAnimation);
        health = 20;
        damage = 5;
        speed = 1;
        typeObject = GhostRed;
    }
};

#endif //UNTITLED4_ENEMYGHOSTRED_H
