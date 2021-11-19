#ifndef UNTITLED4_ENEMYGHOSTWHITE_H
#define UNTITLED4_ENEMYGHOSTWHITE_H

#include "Enemy.h"

class EnemyGhost : public Enemy{
public:
    EnemyGhost(sf::Texture & texture, Animation & animation, const std::map<int, Coordinate>::iterator &iter);
};

#endif //UNTITLED4_ENEMYGHOSTWHITE_H
