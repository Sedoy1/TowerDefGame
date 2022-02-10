#ifndef UNTITLED4_ENEMYGHOSTWHITE_H
#define UNTITLED4_ENEMYGHOSTWHITE_H

#include "Enemy.h"

class EnemyGhostWhite : public Enemy{
public:
    EnemyGhostWhite(sf::Texture & texture, Coordinate & startPosition){
        aSprite.InitSprite(texture, startPosition, 50, 50);
        Animation newAnimation(0, 2, 1.0f, 0.2f);
        aSprite.SetAnimation(newAnimation);
        health = 15;
        damage = 5;
        speed = 3;
        typeObject = GhostWhite;
    }
};

#endif //UNTITLED4_ENEMYGHOSTWHITE_H
