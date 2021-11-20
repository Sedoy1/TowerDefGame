#include "../headers/EnemiesWave.h"

std::vector<std::pair<int, int>> * EnemiesWave::GetEnemiesToSpawn(){
    // Check if there are any enemies
    auto enemiesWaveToSpawn = new std::vector<std::pair<int, int>>;
    auto isEmpty = std::find_if(enemiesNumber.begin(), enemiesNumber.end(),
                                [](const std::pair<int, int> & enemyType){return enemyType.second > 0; });
    if (isEmpty == enemiesNumber.end()){
        waveReleased = true;
    }
    else {
        for (auto iter = enemiesNumber.begin(); iter != enemiesNumber.end(); iter++) {
            if (iter->second > 0) {
                int amountToSpawn = std::min(iter->second, maxSpawnPerTime);
                amountToSpawn = random() % amountToSpawn + 1;
                iter->second -= amountToSpawn;
                enemiesWaveToSpawn->push_back(std::make_pair(iter->first, amountToSpawn));
            }
        }
    }
    return enemiesWaveToSpawn;
}

EnemiesWave::EnemiesWave(int numberEnemiesBlackGhost, int numberEnemiesWhiteGhost){
    enemiesNumber[ENEMY_BLACK_GHOST] = numberEnemiesBlackGhost;
    enemiesNumber[ENEMY_WHITE_GHOST] = numberEnemiesWhiteGhost;
}

// Update waves timer
std::vector<std::pair<int, int>> *EnemiesWave::Update() {
    if(timeStart > duration){
        timeStart = 0;
        return GetEnemiesToSpawn();
    }
    else{
        timeStart += timeStep;
        auto enemiesWaveToSpawn = new std::vector<std::pair<int, int>>;
        return enemiesWaveToSpawn;
    }
}



