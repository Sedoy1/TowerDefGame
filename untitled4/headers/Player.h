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
    
private:
    int money;
    void GetInfo(std:: ostream & os) const override;
};

#endif //UNTITLED4_PLAYER_H
