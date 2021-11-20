#include "../headers/EnemyGhostWhite.h"
EnemyGhostWhite::EnemyGhostWhite(sf::Texture &texture, Animation &animation, Coordinate &startPosition) : Enemy(texture,
                                                                                                                animation,
                                                                                                                startPosition) {
    health = 15;
    damage = 5;
    speed = 3;
}
