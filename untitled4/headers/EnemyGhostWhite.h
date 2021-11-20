#ifndef UNTITLED4_ENEMYGHOSTWHITE_H
#define UNTITLED4_ENEMYGHOSTWHITE_H

#include "Enemy.h"

class EnemyGhostWhite : public Enemy{
public:
    EnemyGhostWhite(sf::Texture & texture, Animation & animation, Coordinate & startPosition);
};

#endif //UNTITLED4_ENEMYGHOSTWHITE_H
