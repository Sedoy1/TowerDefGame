#ifndef UNTITLED4_SNAPSHOT_H
#define UNTITLED4_SNAPSHOT_H
#include "memory"
#include "Player.h"
#include "FriendObject.h"
#include "Enemy.h"

class Snap{
    std::vector<std::shared_ptr<FriendObject>> friendsCopy;
    std::vector<std::shared_ptr<FriendObject>> * friendsPtr;
    std::vector<std::shared_ptr<Enemy>> EnemyCopy;
    std::vector<std::shared_ptr<Enemy>> * EnemyPtr;
    Player playerCopy;
    Player * playerPtr;
public:
    Snap(std::vector<std::shared_ptr<FriendObject>> & friends, std::vector<std::shared_ptr<Enemy>> & enemy,
         Player & player);
    void GetSnap();
};

#endif //UNTITLED4_SNAPSHOT_H
