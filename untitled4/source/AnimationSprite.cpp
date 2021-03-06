#include "../headers/AnimationSprite.h"

void AnimationSprite::Update() {
    UpdateAnimation();
    UpdateMovements();
}

bool AnimationSprite::IsArrived() const {
    return movement.isArrived;
}

void AnimationSprite::UpdateAnimation() {
    if(animation.timeStart >= animation.duration) {
        int new_x = animation.currentAnim * frameWidth;
        //TODO если добавлять анимацию поворота то нужно поключать y
        int new_y = 0;
        sf::Vector2i position(new_x, new_y);
        animation.currentAnim += 1;
        animation.currentAnim %= animation.GetLen();
        sf::Vector2i frame(frameWidth, frameHeight);
        sf::IntRect bounds(position, frame);
        this->setTextureRect(bounds);
        animation.timeStart = 0.0;
    }
    else{
        animation.timeStart += animation.timeStep;
    }
}

void AnimationSprite::UpdateMovements() {
    if(movement.timeStart < movement.GetDuration()){
        movement.isArrived = false;
        sf::Vector2f speed = movement.GetSpeed();
        this->move(speed);
        movement.timeStart += movement.timeStep;
    }
    else{
        movement.isArrived = true;
        movement.timeStart = 0.f;
    }
}

Animation & AnimationSprite::GetAnimation() {
    return animation;
}

void AnimationSprite::SetAnimation(Animation & newAnimation) {
    animation = newAnimation;
}

void AnimationSprite::InitSprite(sf::Texture &newTexture, Coordinate &newPosition, int newFrameWidth, int newFrameHeight) {
    this->setTexture(newTexture);
    this->setPosition(newPosition.x * TileSize, newPosition.y * TileSize);
    //this->setScale(TileSize/newFrameWidth, TileSize/newFrameHeight);
    this->setTextureRect(sf::IntRect(sf::Vector2i (0, 0),sf::Vector2i(newFrameWidth, newFrameHeight)));
    frameWidth = newFrameWidth;
    frameHeight = newFrameHeight;
}

