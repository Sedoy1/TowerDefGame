#ifndef UNTITLED4_FRIENDOBJECT_H
#define UNTITLED4_FRIENDOBJECT_H

#include <ostream>
#include "GameObject.h"
#include "Enemy.h"

class FriendObject: public GameObject{
protected:
    std::vector<std::shared_ptr<Enemy>> * enemyVector;
    std::shared_ptr<Enemy> currentAim;
    int range; //TODO зависимость от position просматривать range и стрелять если возможно
    Coordinate position;
    float shootDelay;
    float timeStep = 1.0f;
    float timeStart = 0.0f;
    bool shotState = false;
    void Shoot();
    void CheckAim();
    void FindNewAim();
    void GetInfo(std:: ostream & os) const override;
public:
    bool GetShootingState() const;
    void SetShootingState(bool newState);
    void Update();
};

#endif //UNTITLED4_FRIENDOBJECT_H
