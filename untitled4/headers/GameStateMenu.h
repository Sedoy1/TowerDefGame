#ifndef UNTITLED4_GAMESTATEMENU_H
#define UNTITLED4_GAMESTATEMENU_H
#include "GameState.h"
#include "GameStatePlaying.h"
#include "BlinkingText.h"

class GameStateMenu : public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    GameStateMenu(Game * game, sf::RenderWindow &window, TextureManager & textureManager);
    ~GameStateMenu();
private:
    void LoadGame();
    void Options();
    void StartGame();
    void InitBg();
    void InitButtons();
    void InitText();
    class RenderManagerMenu: public RenderManager{
    public:
        RenderManagerMenu(sf::RenderWindow &window, TextureManager &textureManager, AnimationSprite &newBgSprite,
                          BlinkingText &newTextMenu, sf::RectangleShape &newButtonStartGame,
                          sf::RectangleShape &newButtonOptions, sf::RectangleShape &newButtonLoadGame,
                          sf::RectangleShape &newButtonExit);
        void Draw();
    private:
        void LoadTextures();
        void DrawBg();
        void DrawButtons();
        void DrawText();
        AnimationSprite * bgSprite;
        BlinkingText * textMenu;
        sf::RectangleShape * buttonStartGame;
        sf::RectangleShape * buttonOptions;
        sf::RectangleShape * buttonLoadGame;
        sf::RectangleShape * buttonExit;
    };
    RenderManagerMenu renderManager;
    AnimationSprite bgSprite;
    BlinkingText textMenu;
    sf::RectangleShape buttonStartGame;
    sf::RectangleShape buttonOptions;
    sf::RectangleShape buttonLoadGame;
    sf::RectangleShape buttonExit;
};


#endif //UNTITLED4_GAMESTATEMENU_H
