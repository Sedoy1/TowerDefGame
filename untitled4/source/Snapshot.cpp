#include "../headers/Snapshot.h"

Snap::Snap(std::vector<std::shared_ptr<FriendObject>> &friends, std::vector<std::shared_ptr<Enemy>> &enemy,
           Player &player) {
    friendsCopy = friends;
    EnemyCopy = enemy;
    playerCopy = player;
}

void Snap::GetSnap() {
    *friendsPtr = friendsCopy;
    *EnemyPtr = EnemyCopy;
    *playerPtr = playerCopy;
}