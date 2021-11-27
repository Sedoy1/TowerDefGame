#ifndef UNTITLED4_SPAWNER_H
#define UNTITLED4_SPAWNER_H
#include "EnemiesWave.h"
#include "EnemyGhostBlack.h"
#include "EnemyGhostWhite.h"
#include "EnemyGhostBrown.h"
#include "EnemyGhostRed.h"
#include "stack"
#include "TextureManager.h"
#include "CannonBlue.h"
#include "CannonBlack.h"
#include "CannonOrange.h"


class Spawner {
private:
    std::stack <EnemiesWave> enemiesWaves;
    std::vector<std::shared_ptr<Enemy>> * enemiesVector;
    std::vector<std::shared_ptr<FriendObject>> * friendsObjects;
    TextureManager & textureManager;
    Coordinate * startEnemyPosition;
    void CreateBlackGhostEnemy();
    void CreateRedGhostEnemy();
    void CreateBrownGhostEnemy();
    void CreateWhiteGhostEnemy();
    void CreateEnemies(int enemiesType);

    bool isWaveEnd = false;
public:
    Spawner(TextureManager &newTextureMng);
    void InitSpawnerOption(std::vector<std::shared_ptr<Enemy>> &newEnemiesVector, Coordinate *newStartEnemyPosition,
                           std::vector<std::shared_ptr<FriendObject>> &friendsVector);
    void UpdateWaves();

    template<typename T>
    void CreateWeapon(T & func, sf::Texture & texture, Coordinate & position);
    void CreateWeaponCannonBlue(Coordinate & position);
    void CreateWeaponCannonOrange(Coordinate & position);
    void CreateWeaponCannonBlack(Coordinate & position);
    void InitWaves();
    bool GetWaveState();
};


#endif //UNTITLED4_SPAWNER_H
