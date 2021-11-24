#include "../headers/Spawner.h"
#include "iostream"

void Spawner::CreateGhostEnemy() {
    std::shared_ptr<Enemy> enemy(new EnemyGhostBlack(textureManager.getTexture(TX_BLACK_GHOST), *startEnemyPosition));
    enemiesVector->push_back(enemy);
    std::cout<<"Black ghost created\n";
}

void Spawner::CreateWhiteGhostEnemy() {
    std::shared_ptr<Enemy> enemy (new EnemyGhostWhite(textureManager.getTexture(TX_WHITE_GHOST), *startEnemyPosition));
    enemiesVector->push_back(enemy);
    std::cout<<"White ghost created\n";
}

Spawner::Spawner(TextureManager &newTextureMng): textureManager(newTextureMng){}
void Spawner::InitWaves() {
    //TODO сделать настраевым уровень сложности(чтобы создавались волны определенного размера и количества)
    for(int i=0; i<7; i++){
        enemiesWaves.push(EnemiesWave(rand()%3+1,rand()%2+1));
    }
}

void Spawner::UpdateWaves() {
    if(!enemiesWaves.empty() && !enemiesWaves.top().IsWaveReleased()){
        auto vector = enemiesWaves.top().Update();
        if (vector != nullptr) {
            for (auto i: *vector) {
                CreateEnemies(i);
            }
        }
    }
    else {
        if(!enemiesWaves.empty()){
            enemiesWaves.pop();
        }
        // enemies spawn was end
        else{
            if(enemiesVector->empty())
                isWaveEnd = true;
            else
                isWaveEnd = false;
        }
    }
}

void Spawner::InitSpawnerOption(std::vector<std::shared_ptr<Enemy>> &newEnemiesVector, Coordinate *newStartEnemyPosition,
                                std::vector<std::shared_ptr<FriendObject>> &friendsVector) {
    enemiesVector = &newEnemiesVector;
    startEnemyPosition = newStartEnemyPosition;
    friendsObjects = &friendsVector;
    InitWaves();
}

void Spawner::CreateEnemies(int enemiesType) {
    //first parameter equal to type of enemy
    switch (enemiesType) {
        case ENEMY_BLACK_GHOST:
            CreateGhostEnemy();
            break;
        case ENEMY_WHITE_GHOST:
            CreateWhiteGhostEnemy();
            break;
    }
}

bool Spawner::GetWaveState() {
    return isWaveEnd;
}

void Spawner::CreateWeaponCannon(Coordinate &position) {
    std::shared_ptr<Cannon> cannon (new Cannon(textureManager.getTexture(TX_CANNON), *enemiesVector, position));
    friendsObjects->push_back(cannon);
}
