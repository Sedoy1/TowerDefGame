#ifndef UNTITLED4_GAMESTATEGAMEOVER_H
#define UNTITLED4_GAMESTATEGAMEOVER_H
#include "GameState.h"
#include "RenderManager.h"

class GameStateGameOver: public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    GameStateGameOver(Game * game, sf::RenderWindow &window, TextureManager & textureManager): GameState(game), renderManger(window, textureManager) {
        SCREEN_HEIGHT = Game_->Window.getSize().y;
        SCREEN_WIDTH = Game_->Window.getSize().x;
        textureManager.LoadTexture(TX_BTN_RESTART, BUTTON_RELOAD);
        textureManager.LoadTexture(TX_BTN_MENU, BUTTON_MENU);
        textureManager.LoadTexture(TX_BTN_EXIT, BUTTON_EXIT);
        InitText();
        InitButtons();
    }
    ~GameStateGameOver() override;
private:
    void InitText();
    void InitButtons();
    void RestartGame();
    void Back2Menu();
    class RenderManagerGameOver: public RenderManager{
    public:
        RenderManagerGameOver(sf::RenderWindow & window, TextureManager & textureManager): RenderManager(window, textureManager){}
        void Draw(sf::Text & newTextGameOver, sf::RectangleShape & newButtonRestart, sf::RectangleShape &newButtonMenu,
                  sf::RectangleShape &newButtonExit);

    private:
        void DrawButtons(sf::RectangleShape &newButtonRestart, sf::RectangleShape &newButtonMenu,
                         sf::RectangleShape &newButtonExit);
        void DrawText(sf::Text & newTextGameOver);
        friend GameStateGameOver;
    };
    RenderManagerGameOver renderManger;
    sf::Text textGameOver;
    sf::RectangleShape buttonExit;
    sf::RectangleShape buttonRestart;
    sf::RectangleShape buttonBackMenu;
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
    friend RenderManagerGameOver;
};


#endif //UNTITLED4_GAMESTATEGAMEOVER_H
