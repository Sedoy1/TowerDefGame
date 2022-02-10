#ifndef UNTITLED4_ENEMY_H
#define UNTITLED4_ENEMY_H

#include <ostream>
#include "GameObject.h"

enum EnemyType{
    GhostBlack,
    GhostBrown,
    GhostRed,
    GhostWhite
};

class Enemy : public GameObject{
protected:
    int currentStep = 0;
    int speed;
    int typeObject;
public:
    void GetInfo(std:: ostream & os) const override;
    void SetSpeed(int newSpeed){speed = newSpeed;}
    int GetSpeed() const{return speed;}
    int GetStep() const{return currentStep;}
    void NextStep(){currentStep += 1;}
};

#endif //UNTITLED4_ENEMY_H
