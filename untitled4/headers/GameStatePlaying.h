#ifndef UNTITLED4_GAMESTATEPLAYING_H
#define UNTITLED4_GAMESTATEPLAYING_H
#include "GameState.h"
#include "GameObject.h"
#include "GameLogic.h"
#include "RenderManagerPlay.h"
#include "Player.h"

class GameStatePlaying : public GameState{
    public:
        void StateRealization() override;
        void HandleInput() override;
        void Update() override;
        GameStatePlaying(Game * game, sf::RenderWindow &window, TextureManager & textureManager);
        ~GameStatePlaying() override;
    private:
        void InitLevelComplexity();
        void SpawnEnemies();
        void InitPlayer();
        GameLogic LogicEvent;
        RenderManagerPlay RenderMnr;
        std::map<int, int> EnemiesNumber;
        std::vector<Enemy * > Enemies;
        std::shared_ptr<Player> player;
};

#endif //UNTITLED4_GAMESTATEPLAYING_H
