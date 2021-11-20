#include "../headers/Spawner.h"
#include "iostream"

//TODO спавнивтаь нужно с переодичностью в проходе цикла, тк накладываются можельки
void Spawner::CreateGhostEnemy() {
    Animation new_animation(0, 2, 1.0f, 0.2f);
    auto * enemy = new EnemyGhost(textureManager.getTexture(TX_BLACK_GHOST), new_animation, *startEnemyPosition);
    enemiesVector->push_back(enemy);
    std::cout<<"Black ghost created\n";
}

void Spawner::CreateWhiteGhostEnemy() {
    Animation new_animation(0, 2, 1.0f, 0.2f);
    auto * enemy = new EnemyGhostWhite(textureManager.getTexture(TX_WHITE_GHOST), new_animation, *startEnemyPosition);
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
        for(auto i: *vector){
            CreateEnemies(i);
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

void Spawner::InitSpawnerOption(std::vector<Enemy *> *newEnemiesVector, Coordinate *newStartEnemyPosition) {
    enemiesVector = newEnemiesVector;
    startEnemyPosition = newStartEnemyPosition;
    InitWaves();
}

void Spawner::CreateEnemies(std::pair<int, int> enemiesParams) {
    //first parameter equal to type of enemy
    switch (enemiesParams.first) {
        case ENEMY_BLACK_GHOST:
            for(int count = 0; count<enemiesParams.second; count++){
                CreateGhostEnemy();
            }
            break;
        case ENEMY_WHITE_GHOST:
            for(int count = 0; count<enemiesParams.second; count++){
                CreateWhiteGhostEnemy();
            }
            break;
    }
}

bool Spawner::GetWaveState() {
    return isWaveEnd;
}
