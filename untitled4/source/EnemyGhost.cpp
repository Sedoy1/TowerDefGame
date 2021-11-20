#include "../headers/EnemyGhost.h"

EnemyGhost::EnemyGhost(sf::Texture &texture, Animation &animation, Coordinate & startPosition):
Enemy(texture, animation, startPosition) {
    //TODO перенести анимацию и текстуру определиня в класс
    health = 10;
    damage = 10;
    speed = 2;
}
