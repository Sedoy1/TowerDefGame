#include "../headers/EnemyGhostWhite.h"

EnemyGhost::EnemyGhost(sf::Texture &texture, Animation &animation, const std::map<int, Coordinate>::iterator & iter):
        Enemy(texture, animation, iter) {
    health = 15;
    damage = 5;
    speed = 3;
}