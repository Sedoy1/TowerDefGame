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
    Animation animation;
public:
    //constructor for arr use only in tiles
    AnimationSprite() = default;
    void InitSprite(sf::Texture &newTexture, Coordinate &newPosition);
    void Update();
    bool IsArrived() const;
    void SetAnimation(Animation & newAnimation);
    Animation & GetAnimation();
    Movement movement;
};

#endif //UNTITLED4_ANIMATIONSPRITE_H
