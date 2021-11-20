#ifndef UNTITLED4_ENEMY_H
#define UNTITLED4_ENEMY_H
#include "GameObject.h"


class Enemy : public GameObject{
protected:
    int currentStep = 0;
    int speed;
public:
    Enemy(sf::Texture & texture, Animation & animation, Coordinate & startPosition):
    GameObject(texture, animation, startPosition){}
    void SetSpeed(int newSpeed){speed = newSpeed;}
    int GetSpeed(){return speed;}
    int GetStep(){return currentStep;}
    void NextStep(){currentStep += 1;}
};

#endif //UNTITLED4_ENEMY_H
