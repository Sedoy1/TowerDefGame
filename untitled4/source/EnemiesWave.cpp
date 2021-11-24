#include "../headers/EnemiesWave.h"

std::vector<int> * EnemiesWave::GetEnemiesToSpawn(){
    // Check if there are any enemies
    auto enemiesWaveToSpawn = new std::vector<int>;
    auto isEmpty = std::find_if(enemiesNumber.begin(), enemiesNumber.end(),
                                [](const std::pair<int, int> & enemyType){return enemyType.second > 0; });
    if (isEmpty == enemiesNumber.end()){
        waveReleased = true;
    }
    else {
        for (auto iter = enemiesNumber.begin(); iter != enemiesNumber.end(); iter++) {
            if (iter->second > 0) {
                iter->second -= 1;
                enemiesWaveToSpawn->push_back(iter->first);
            }
        }
    }
    return enemiesWaveToSpawn;
}

EnemiesWave::EnemiesWave(int numberEnemiesBlackGhost, int numberEnemiesWhiteGhost, int numberEnemiesRedGhost,
                         int numberEnemiesBrownGhost) {
    enemiesNumber[ENEMY_BLACK_GHOST] = numberEnemiesBlackGhost;
    enemiesNumber[ENEMY_WHITE_GHOST] = numberEnemiesWhiteGhost;
    enemiesNumber[ENEMY_RED_GHOST] = numberEnemiesRedGhost;
    enemiesNumber[ENEMY_BROWN_GHOST] = numberEnemiesBrownGhost;
}

// Update waves timer
std::vector<int> * EnemiesWave::Update() {
    if(timeStart > duration){
        timeStart = 0;
        return GetEnemiesToSpawn();
    }
    else{
        timeStart += timeStep;
        return nullptr;
    }
}



