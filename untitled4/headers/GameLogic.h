#ifndef UNTITLED4_GAMELOGIC_H
#define UNTITLED4_GAMELOGIC_H
#include "EnemyGhost.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "memory"

enum{
    ENEMY_BLACK_GHOST,
    ENEMY_WHITE_GHOST,
    ENEMY_BLUE_GHOST,
    ENEMY_RED_GHOST
};

class GameLogic {
    private:
    /*Function create and init Enemy Type 1
 *return ptr on this obj*/
    std::map<int, Coordinate> *enemiesPath;
    Enemy * CreateGhostEnemy(sf::Texture &texture);
    void MoveEnemies();
    int ComputeDirection(int direction1, int direction2);
    std::vector<Enemy *> * vectorEnemy;
    std::shared_ptr<Player> player;
    public:
    ~GameLogic();
    void SetPlayableRules(std::map<int, Coordinate> *newEnemyPath, std::vector<Enemy *> * newVectorEnemy, const std::shared_ptr<Player>& newPlayer);
    /*Add new Enemy to the vector*/
    void SpawnEnemy();
    void AddEnemy(int id, sf::Texture & TX_ENEMY);
    void MoveObject();
    bool IsPlayerAlive();
};


#endif //UNTITLED4_GAMELOGIC_H
