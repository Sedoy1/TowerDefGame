#include "../headers/Spawner.h"
#include "iostream"

void Spawner::CreateRedGhostEnemy() {
    std::shared_ptr<Enemy> enemy(new EnemyGhostRed(textureManager.GetTexture(TX_RED_GHOST), *startEnemyPosition));
    enemiesVector->push_back(enemy);
    std::cout<<"Red ghost created\n";
}

void Spawner::CreateBrownGhostEnemy() {
    std::shared_ptr<Enemy> enemy(new EnemyGhostBrown(textureManager.GetTexture(TX_BROWN_GHOST), *startEnemyPosition));
    enemiesVector->push_back(enemy);
    std::cout<<"Brown ghost created\n";
}

void Spawner::CreateBlackGhostEnemy() {
    std::shared_ptr<Enemy> enemy(new EnemyGhostBlack(textureManager.GetTexture(TX_BLACK_GHOST), *startEnemyPosition));
    enemiesVector->push_back(enemy);
    std::cout<<"Black ghost created\n";
}

void Spawner::CreateWhiteGhostEnemy() {
    std::shared_ptr<Enemy> enemy (new EnemyGhostWhite(textureManager.GetTexture(TX_WHITE_GHOST), *startEnemyPosition));
    enemiesVector->push_back(enemy);
    std::cout<<"White ghost created\n";
}
Spawner::Spawner(TextureManager &newTextureMng): textureManager(newTextureMng){}

void Spawner::InitWaves() {
    //TODO сделать настраевым уровень сложности(чтобы создавались волны определенного размера и количества)
    for(int i=0; i<7; i++){
        enemiesWaves.push(EnemiesWave(rand() % 3 + 1,
                                      rand() % 2 + 1, rand() % 4 + 1,rand() % 6 + 1));
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
            CreateBlackGhostEnemy();
            break;
        case ENEMY_WHITE_GHOST:
            CreateWhiteGhostEnemy();
            break;
        case ENEMY_RED_GHOST:
            CreateRedGhostEnemy();
            break;
        case ENEMY_BROWN_GHOST:
            CreateBrownGhostEnemy();
            break;
    }
}

bool Spawner::GetWaveState() {
    return isWaveEnd;
}

std::shared_ptr<CannonBlue> Spawner::CreateWeaponCannonBlue(Coordinate &position) {
    std::shared_ptr<CannonBlue> cannon (new CannonBlue(textureManager.GetTexture(TX_BLUE_CANNON), *enemiesVector, position));
    return cannon;
}

std::shared_ptr<CannonOrange> Spawner::CreateWeaponCannonOrange(Coordinate &position) {
    std::shared_ptr<CannonOrange> cannon (new CannonOrange(textureManager.GetTexture(TX_ORANGE_CANNON), *enemiesVector, position));
    return cannon;
}

std::shared_ptr<CannonBlack> Spawner::CreateWeaponCannonBlack(Coordinate &position) {
    std::shared_ptr<CannonBlack> cannon (new CannonBlack(textureManager.GetTexture(TX_BLACK_CANNON), *enemiesVector, position));
    return cannon;
}
