#ifndef UNTITLED4_ENEMY_H
#define UNTITLED4_ENEMY_H

#include <ostream>
#include "GameObject.h"


class Enemy : public GameObject{
protected:
    int currentStep = 0;
    int speed;
    void GetInfo(std:: ostream & os) const override;
public:
    void SetSpeed(int newSpeed){speed = newSpeed;}
    int GetSpeed() const{return speed;}
    int GetStep() const{return currentStep;}
    void NextStep(){currentStep += 1;}
};

#endif //UNTITLED4_ENEMY_H
