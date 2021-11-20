#include <iostream>
#include "../headers/GameLogic.h"
#include "../headers/ElementsDefinition.h"

void GameLogic::MoveEnemies() {
    for(auto enemy: *vectorEnemy){
        // last element of path is Finish, finish is player
        if(enemiesPath->rbegin()->first > enemy->GetStep()){
            if (enemy->GetSprite().IsArrived()) {
                int x = enemy->GetSpeed();
                int y = x;
                x *= ComputeDirection(enemiesPath->at(enemy->GetStep()).x, enemiesPath->at(enemy->GetStep() + 1).x);
                y *= ComputeDirection(enemiesPath->at(enemy->GetStep()).y, enemiesPath->at(enemy->GetStep() + 1).y);
                enemy->GetSprite().movement.SetSpeed(x, y);
                enemy->NextStep();
            }
        }
        else{
            int newHp = player->GetHealth() - enemy->GetDamage();
            player->SetHealth(newHp);
            vectorEnemy->erase(std::find(vectorEnemy->begin(), vectorEnemy->end(), enemy));
            delete enemy;
        }
    }
}

void GameLogic::SetPlayableRules(std::map<int, Coordinate> *newEnemyPath, std::vector<Enemy *> * newVectorEnemy, const std::shared_ptr<Player>& newPlayer) {
    enemiesPath = newEnemyPath;
    vectorEnemy = newVectorEnemy;
    player = newPlayer;
}

void GameLogic::MoveObject() {
    MoveEnemies();
}

int GameLogic::ComputeDirection(int direction1, int direction2) {
    if (direction1 > direction2)
        return -1;
    else if (direction1 == direction2)
        return 0;
    return 1;
}

GameLogic::~GameLogic() {
    delete enemiesPath;
}

bool GameLogic::IsPlayerAlive() {
    if(player->GetHealth() > 0)
        return true;
    else
        return false;
}
