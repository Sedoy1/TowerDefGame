#ifndef UNTITLED4_GAMESTATEPLAYING_H
#define UNTITLED4_GAMESTATEPLAYING_H
#include "GameState.h"
#include "GameObject.h"
#include "GameLogic.h"
#include "GameField.h"
#include "Player.h"
#include "Spawner.h"
#include "GameStateGameOver.h"

class GameStatePlaying : public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    GameStatePlaying(Game * game, sf::RenderWindow &window, TextureManager & newTextureManager);
    ~GameStatePlaying() override;
private:
    // subclass of render objects
    class RenderManagerPlay: public RenderManager{
    private:
        GameField gameField;
        void DrawField();
        void DrawEnemies(std::vector<Enemy *> &enemyVector);
        void LoadField();
        void LoadEnemies();
    public:
        RenderManagerPlay(sf::RenderWindow &window, TextureManager & textureManager):RenderManager(window, textureManager){LoadField(); LoadEnemies();}
        ~RenderManagerPlay();
        std::map<int, Coordinate> * EnemyPath();
        void Draw(std::vector<Enemy *> &enemyVector, const std::shared_ptr<Player> &player);
        static unsigned int TILE_HEIGHT;
        static unsigned int TILE_WIDTH;
        void DrawPlayer(const std::shared_ptr<Player> &player);
    };

    void GameOver();
    void Win();
    TextureManager & textureManager;
    void InitPlayer();
    GameLogic LogicEvent;
    RenderManagerPlay RenderMnr;
    Spawner spawnerManager;
    std::vector<Enemy * > Enemies;
    std::shared_ptr<Player> player;
};

#endif //UNTITLED4_GAMESTATEPLAYING_H
