#ifndef UNTITLED4_GAMELOGIC_H
#define UNTITLED4_GAMELOGIC_H
#include "Enemy.h"
#include "Player.h"
#include "FriendObject.h"
#include "SFML/Graphics.hpp"
#include "memory"
#include "GameField.h"

enum{
    ENEMY_BLACK_GHOST,
    ENEMY_WHITE_GHOST,
    ENEMY_BLUE_GHOST,
    ENEMY_RED_GHOST
};

class GameLogic {
    private:
    void MoveEnemies();
    void WeaponsShot();
    void CheckEnemiesViability();
    void DoAnimation();
    int ComputeDirection(int direction1, int direction2);
    std::map<int, Coordinate> * enemiesPath;
    std::vector<std::shared_ptr<Enemy>> * vectorEnemy;
    std::vector<std::shared_ptr<FriendObject>> * vectorFriends;
    GameField * gameField;
    Player * player;
    public:
    void SetPlayableRules(std::map<int, Coordinate> &newEnemyPath, std::vector<std::shared_ptr<Enemy>> &newVectorEnemy,
                          Player &newPlayer, std::vector<std::shared_ptr<FriendObject>> &newVectorFriends,
                          GameField &newGameField);
    /*Add new Enemy to the vector*/
    void GameRealization();
    bool IsPlayerAlive();
};


#endif //UNTITLED4_GAMELOGIC_H
