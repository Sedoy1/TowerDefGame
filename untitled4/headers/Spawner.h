#ifndef UNTITLED4_SPAWNER_H
#define UNTITLED4_SPAWNER_H
#include "EnemiesWave.h"
#include "EnemyGhostBlack.h"
#include "EnemyGhostWhite.h"
#include "stack"
#include "TextureManager.h"

class Spawner {
private:
    std::stack <EnemiesWave> enemiesWaves;
    std::vector<Enemy * > * enemiesVector;
    TextureManager & textureManager;
    Coordinate * startEnemyPosition;
    void CreateGhostEnemy();
    void CreateWhiteGhostEnemy();
    void CreateEnemies(int enemiesType);
    bool isWaveEnd = false;
public:
    Spawner(TextureManager &newTextureMng);
    void InitSpawnerOption(std::vector<Enemy * > * newEnemiesVector, Coordinate * newStartEnemyPosition);
    void UpdateWaves();
    void CreateWeaponCannon(Coordinate & position);
    void InitWaves();
    bool GetWaveState();
};


#endif //UNTITLED4_SPAWNER_H
