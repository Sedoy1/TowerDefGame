#ifndef UNTITLED4_ANIMATIONSPRITE_H
#define UNTITLED4_ANIMATIONSPRITE_H
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Movement.h"
#include "Coordinate.h"
#include "memory"

class AnimationSprite : public sf::Sprite{
private:
    //TODO in future should init these param in constructor
    const int frameWidth = 50;
    const int frameHeight = 50;
    void UpdateAnimation();
    void UpdateMovements();
public:
    AnimationSprite(sf::Texture & texture, Animation & new_animation, Coordinate coord): animation(new_animation), movement(1){
        this->setTexture(texture);
        this->setPosition(coord.x * frameWidth, coord.y * frameHeight);
    }
    //constructor for arr use only in tiles
    AnimationSprite() = default;
    void Update();
    bool IsArrived() const;
    Movement movement;
    Animation animation;
};

#endif //UNTITLED4_ANIMATIONSPRITE_H
