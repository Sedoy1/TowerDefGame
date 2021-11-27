#ifndef UNTITLED4_GAMESTATEGAMEEND_H
#define UNTITLED4_GAMESTATEGAMEEND_H
#include "GameState.h"
#include "RenderManager.h"

enum{
    WIN,
    LOOSE
};

class GameStateGameEnd: public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    GameStateGameEnd(Game * game, sf::RenderWindow &window, TextureManager & textureManager, int endID):
    GameState(game), renderManger(window, textureManager) {
        renderManger.LoadTexture();
        //InitBg(endID);
        InitText(endID);
        InitButtons();
    }
    ~GameStateGameEnd() override;
private:
    void InitBg(int endID);
    void InitText(int endID);
    void InitButtons();
    void RestartGame();
    void Back2Menu();
    class RenderManagerGameOver: public RenderManager{
    public:
        RenderManagerGameOver(sf::RenderWindow & window, TextureManager & textureManager): RenderManager(window, textureManager){}
        void Draw(sf::Text &newTextGameOver, sf::RectangleShape &newButtonRestart, sf::RectangleShape &newButtonMenu,
                  sf::RectangleShape &newButtonExit, sf::RectangleShape &newBgTexture);
        void LoadTexture();

    private:
        void DrawButtons(sf::RectangleShape &newButtonRestart, sf::RectangleShape &newButtonMenu,
                         sf::RectangleShape &newButtonExit);
        void DrawText(sf::Text & newTextGameOver);
        void DrawBg(sf::RectangleShape & newBgTexture);
        friend GameStateGameEnd;
    };
    RenderManagerGameOver renderManger;
    sf::Text textGameResult;
    sf::RectangleShape buttonExit;
    sf::RectangleShape buttonRestart;
    sf::RectangleShape buttonBackMenu;
    sf::RectangleShape bgTexture;
};


#endif //UNTITLED4_GAMESTATEGAMEEND_H
