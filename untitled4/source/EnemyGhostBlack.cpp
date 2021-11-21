#include "../headers/EnemyGhostBlack.h"

EnemyGhostBlack::EnemyGhostBlack(sf::Texture &texture, Coordinate & startPosition){
    aSprite.InitSprite(texture, startPosition);
    Animation newAnimation(0, 2, 1.0f, 0.2f);
    aSprite.SetAnimation(newAnimation);
    health = 10;
    damage = 10;
    speed = 2;
}
