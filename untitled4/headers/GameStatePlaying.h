#ifndef UNTITLED4_GAMESTATEPLAYING_H
#define UNTITLED4_GAMESTATEPLAYING_H
#include "GameState.h"
#include "GameObject.h"
#include "GameLogic.h"
#include "GameField.h"
#include "Player.h"
#include "Spawner.h"
#include "GameStateGameEnd.h"
#include "GameStatePause.h"

class   GameStatePlaying : public GameState{
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
        void DrawField(GameField &newGameField);
        void DrawEnemies(std::vector<std::shared_ptr<Enemy>> &enemyVector);
        void DrawButtons(sf::RectangleShape &newButtonPause, sf::RectangleShape &newButtonSave);
        void LoadObjectsTexture();
        void LoadFieldTexture();
        void LoadButtonsTexture();
    public:
        RenderManagerPlay(sf::RenderWindow &window, TextureManager & textureManager);
        ~RenderManagerPlay();
        void Draw(std::vector<std::shared_ptr<Enemy>> &enemyVector, const std::shared_ptr<Player> &player, GameField &gameField,
                  sf::RectangleShape &buttonPause, sf::RectangleShape &buttonSave);
        static unsigned int TILE_HEIGHT;
        static unsigned int TILE_WIDTH;
        void DrawPlayer(const std::shared_ptr<Player> &player);
    };

    void GameOver();
    void Win();
    void Pause();
    void InitPlayer();
    void LoadField();
    void InitButtons();
    GameField gameField;
    GameLogic LogicEvent;
    RenderManagerPlay RenderMnr;
    Spawner spawnerManager;
    std::vector<std::shared_ptr<Enemy> > Enemies;
    std::map<int, Coordinate> enemyPath;
    std::shared_ptr<Player> player;
    sf::RectangleShape buttonPauseContinue;
    sf::RectangleShape buttonSave;
    TextureManager & textureManager;
};

#endif //UNTITLED4_GAMESTATEPLAYING_H
