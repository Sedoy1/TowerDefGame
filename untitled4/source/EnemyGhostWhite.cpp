#include "../headers/EnemyGhostWhite.h"
EnemyGhostWhite::EnemyGhostWhite(sf::Texture &texture, Coordinate &startPosition){
    aSprite.InitSprite(texture, startPosition, 50, 50);
    Animation newAnimation(0, 2, 1.0f, 0.2f);
    aSprite.SetAnimation(newAnimation);
    health = 15;
    damage = 5;
    speed = 3;
}
