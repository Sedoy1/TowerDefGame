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
    int frameWidth=50;
    int frameHeight=50;
    void UpdateAnimation();
    void UpdateMovements();
    Animation animation;
    const float TileSize = 50.0f;
public:
    //constructor for arr use only in tiles
    AnimationSprite() = default;
    void InitSprite(sf::Texture &newTexture, Coordinate &newPosition, int newFrameWidth=50, int newFrameHeight=50);
    void Update();
    bool IsArrived() const;
    void SetAnimation(Animation & newAnimation);
    Animation & GetAnimation();
    Movement movement;
};

#endif //UNTITLED4_ANIMATIONSPRITE_H
