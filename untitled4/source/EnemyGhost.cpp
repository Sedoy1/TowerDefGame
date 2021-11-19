#include "../headers/EnemyGhost.h"

EnemyGhost::EnemyGhost(sf::Texture &texture, Animation &animation, const std::map<int, Coordinate>::iterator & iter):
Enemy(texture, animation, iter) {
    //TODO перенести анимацию и текстуру определиня в класс
    health = 10;
    damage = 10;
    speed = 2;
}
