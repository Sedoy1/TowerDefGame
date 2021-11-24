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
#include "Cannon.h"

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
        //TODO передавать параметры через функцию?
    private:
        void DrawField();
        void DrawEnemies();
        void DrawButtons();
        void DrawFriendsObjects();
        void DrawPlayer();
        void LoadObjectsTexture();
        void LoadFieldTexture();
        void LoadButtonsTexture();
        std::vector<std::shared_ptr<Enemy>> * enemyVector;
        Player * player;
        GameField *gameField;
        sf::RectangleShape * buttonPause;
        sf::RectangleShape * buttonSave;
        std::vector<std::shared_ptr<FriendObject>> * friendVector;
    public:
        RenderManagerPlay(sf::RenderWindow &window, TextureManager & textureManager, std::vector<std::shared_ptr<Enemy>> &enemyVector,
                          Player & player, GameField &gameField,
                          sf::RectangleShape &buttonPause, sf::RectangleShape &buttonSave, std::vector<std::shared_ptr<FriendObject>> &friendVector);
        ~RenderManagerPlay();
        void Draw();
        static unsigned int TILE_HEIGHT;
        static unsigned int TILE_WIDTH;
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
    std::vector<std::shared_ptr<FriendObject>> FriendObjects;
    std::map<int, Coordinate> enemyPath;
    Player player;
    sf::RectangleShape buttonPauseContinue;
    sf::RectangleShape buttonSave;
    TextureManager & textureManager;
};

#endif //UNTITLED4_GAMESTATEPLAYING_H
