#ifndef UNTITLED4_FRIENDOBJECT_H
#define UNTITLED4_FRIENDOBJECT_H
#include "GameObject.h"
#include "Enemy.h"

class FriendObject: public GameObject{
protected:
    std::vector<std::shared_ptr<Enemy>> * enemyVector;
    std::shared_ptr<Enemy> currentAim;
    int range;
    Coordinate position;
    float shootDelay;
    float timeStep = 1.0f;
    float timeStart = 0.0f;
    bool shotState = false;
    void Shoot();
    void CheckAim();
    void FindNewAim();
public:
    bool GetShootingState();
    void SetShootingState(bool newState);
    void Update();
};

#endif //UNTITLED4_FRIENDOBJECT_H
