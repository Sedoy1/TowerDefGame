#ifndef UNTITLED4_ENEMYGHOST_H
#define UNTITLED4_ENEMYGHOST_H
#include "Enemy.h"

class EnemyGhost : public Enemy{
    public:
        EnemyGhost(sf::Texture & texture, Animation & animation, Coordinate & startPosition);
};


#endif //UNTITLED4_ENEMYGHOST_H
