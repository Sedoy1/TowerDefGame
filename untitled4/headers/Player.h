#ifndef UNTITLED4_PLAYER_H
#define UNTITLED4_PLAYER_H
#include "GameObject.h"

class Player:public GameObject{
public:
    void InitPlayer(sf::Texture & texture, Coordinate & newPosition){
        aSprite.InitSprite(texture, newPosition, 50, 50);
        Animation newAnimation(0, 2, 1.0f, 0.2f);
        aSprite.SetAnimation(newAnimation);
        health = 100;
        damage = 0;
        money = 100;
    }
    void GetInfo(std:: ostream & os) const override;
    Player & operator = (const Player & other){
        this->money = other.money;
        this->health = other.health;
        return *this;
    }
private:
    int money;
};

#endif //UNTITLED4_PLAYER_H
