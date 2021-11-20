#ifndef UNTITLED4_ENEMIESWAVE_H
#define UNTITLED4_ENEMIESWAVE_H

#include <iostream>
#include "GameLogic.h"

class EnemiesWave{
private:
    std::map<int, int> enemiesNumber;
    // GetEnemiesToSpawn duration should be get value from constructor to modern waves
    float duration = 120.0f;
    float timeStep = 1.0f;
    float timeStart = 0.0f;
    // Number of enemies which can be spawn at once should be got the value from constructor
    int maxSpawnPerTime = 3;
    bool waveReleased = false;
    std::vector<std::pair<int, int>> * GetEnemiesToSpawn();
public:
    EnemiesWave(int numberEnemiesBlackGhost, int numberEnemiesWhiteGhost);
    // return an enemies types to spawn
    std::vector<std::pair<int, int>> * Update();
    bool IsWaveReleased() const{return waveReleased;}
};

#endif //UNTITLED4_ENEMIESWAVE_H
