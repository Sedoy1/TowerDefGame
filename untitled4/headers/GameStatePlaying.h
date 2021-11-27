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
#include "CannonBlack.h"
#include "Logger.h"

class   GameStatePlaying : public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    GameStatePlaying(Game * game, sf::RenderWindow &window, TextureManager & newTextureManager);
    ~GameStatePlaying() override;
private:
    enum{
        NoCannonID,
        CannonBlueID,
        CannonOrangeID,
        CannonBlackID
    };
    // subclass of render objects
    class RenderManagerPlay: public RenderManager{
        //TODO передавать параметры через функцию? можно передать так же объект Gamestate И получить из него все объекты, но тогда будет циклическая зависимость
    private:
        void DrawField();
        void DrawEnemies();
        void DrawButtons();
        void DrawFriendsObjects();
        void DrawPlayer();
        void DrawHealth();
        void LoadObjectsTexture();
        void LoadFieldTexture();
        void LoadButtonsTexture();
        std::vector<std::shared_ptr<Enemy>> * enemyVector;
        GameField *gameField;
        sf::RectangleShape * buttonPause;
        sf::RectangleShape * buttonSave;
        std::vector<std::shared_ptr<FriendObject>> * friendVector;
        std::vector<sf::RectangleShape> * vectorButtonsWeapons;
        sf::RectangleShape * labelWeaponsButtons;
        sf::Sprite * health;
        sf::Text * healthText;
        Player * player;
    public:
        RenderManagerPlay(sf::RenderWindow &window, TextureManager &textureManager,
                          std::vector<std::shared_ptr<Enemy>> &enemyVector, Player &player, GameField &gameField,
                          sf::RectangleShape &buttonPause, sf::RectangleShape &buttonSave,
                          std::vector<std::shared_ptr<FriendObject>> &friendVector,
                          std::vector<sf::RectangleShape> &buttonsWeapons, sf::RectangleShape &labelButtons, sf::Text & textHealth,sf::Sprite &newHealth);
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
    void InitHealth();
    void LoggerAction();
    GameField gameField;
    GameLogic LogicEvent;
    RenderManagerPlay RenderMnr;
    Spawner spawnerManager;
    TextureManager & globalTextureManager;
    std::vector<std::shared_ptr<Enemy> > Enemies;
    std::vector<std::shared_ptr<FriendObject>> FriendObjects;
    std::map<int, Coordinate> enemyPath;
    std::vector<sf::RectangleShape> buttonsWeapon{3};
    sf::RectangleShape buttonPauseContinue;
    sf::RectangleShape buttonSave;
    sf::RectangleShape labelChoiceWeapons;
    sf::Sprite healthSprite;
    sf::Text healthInfo;
    sf::Font font;
    Player player;
    int selectedCannonId = NoCannonID;
    Logger logger;
};

#endif //UNTITLED4_GAMESTATEPLAYING_H
