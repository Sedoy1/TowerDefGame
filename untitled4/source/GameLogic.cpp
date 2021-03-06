#include <iostream>
#include "../headers/GameLogic.h"
#include "../headers/ElementsDefinition.h"

void GameLogic::MoveEnemies() {
    for(auto enemy = vectorEnemy->begin(); enemy!= vectorEnemy->end();){
        // last element of path is Finish, finish is player
        if(enemiesPath->rbegin()->first > (*enemy)->GetStep() ){
            if ((*enemy)->GetSprite().IsArrived()) {
                int x = (*enemy)->GetSpeed();
                int y = x;
                x *= ComputeDirection(enemiesPath->at((*enemy)->GetStep()).x, enemiesPath->at((*enemy)->GetStep() + 1).x);
                y *= ComputeDirection(enemiesPath->at((*enemy)->GetStep()).y, enemiesPath->at((*enemy)->GetStep() + 1).y);
                (*enemy)->GetSprite().movement.SetSpeed(x, y);
                (*enemy)->NextStep();
            }
            enemy++;
        }
        else{
            int newHp = player->GetHealth() - (*enemy)->GetDamage();
            player->SetHealth(newHp);
            enemy = vectorEnemy->erase(enemy);
        }
    }
}

void GameLogic::SetPlayableLogic(std::map<int, Coordinate> &newEnemyPath,
                                 std::vector<std::shared_ptr<Enemy>> &newVectorEnemy,
                                 Player &newPlayer, std::vector<std::shared_ptr<FriendObject>> &newVectorFriends,
                                 GameField &newGameField, sf::Text &newTextHealth) {
    enemiesPath = &newEnemyPath;
    vectorEnemy = &newVectorEnemy;
    vectorFriends = &newVectorFriends;
    player = &newPlayer;
    gameField = &newGameField;
    textHealth = &newTextHealth;
}

int GameLogic::ComputeDirection(int direction1, int direction2) {
    if (direction1 > direction2)
        return -1;
    else if (direction1 == direction2)
        return 0;
    return 1;
}

bool GameLogic::IsPlayerDead() {
    if(player->GetHealth() > 0)
        return false;
    else
        return true;
}

void GameLogic::GameRealization() {
    WeaponsShot();
    CheckEnemiesViability();
    DoAnimation();
    MoveEnemies();
}

void GameLogic::WeaponsShot() {
    for (auto weapon: *vectorFriends){
        weapon->Update();
    }
}

void GameLogic::CheckEnemiesViability() {
    for(auto enemy = vectorEnemy->begin(); enemy != vectorEnemy->end();){
        if ((*enemy)->GetHealth() < 0){
            enemy = vectorEnemy->erase(enemy);
        }
        else{
            enemy ++;
        }
    }
}

void GameLogic::DoAnimation() {
    //animation for enemies
    for(auto object: *vectorEnemy){
        object->GetSprite().Update();
    }

    //animation for field
    for(GameField::Iterator iterator = gameField->Begin(); iterator != gameField->End(); iterator ++){
        iterator.GetTile().GetTile().Update();
    }

    //animation for friends
    for(auto weapon : *vectorFriends) {
        if (weapon->GetShootingState()) {
            if (weapon->GetSprite().GetAnimation().currentAnim == weapon->GetSprite().GetAnimation().endFrame)
                weapon->SetShootingState(false);
            weapon->GetSprite().Update();
        }
    }

    //animation player
    player->GetSprite().Update();

    textHealth->setString(std::to_string(player->GetHealth()));
}
