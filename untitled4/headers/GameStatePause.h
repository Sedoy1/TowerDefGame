#ifndef UNTITLED4_GAMESTATEPAUSE_H
#define UNTITLED4_GAMESTATEPAUSE_H
#include "GameState.h"
#include "BlinkingText.h"

class GameStatePause: public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    void InitButtons();
    void InitBg(sf::Texture *newBgTexture);
    GameStatePause(Game *game, sf::RenderWindow &window, TextureManager &textureManager, sf::Texture *newTexturePause) :
            GameState(game),renderManager(window, textureManager) {
        renderManager.LoadTexture();
        InitBg(newTexturePause);
        InitText();
        InitButtons();
    }

private:
    class RenderManagerPause: public RenderManager{
    public:
        RenderManagerPause(sf::RenderWindow & window, TextureManager & textureManager): RenderManager(window, textureManager){}
        void Draw(BlinkingText &newTextPause, sf::RectangleShape &newButtonContinue,
                  sf::RectangleShape &newButtonSave, sf::RectangleShape &bgShape);
        void LoadTexture();

    private:
        void DrawButtons(sf::RectangleShape & newButtonContinue, sf::RectangleShape &newButtonSave);
        void DrawText(BlinkingText &newTextPause);
        void DrawBg(sf::RectangleShape & newBgShape);
        friend GameStatePause;
    };
    void SaveGame();
    void ContinueGame();
    void InitText();
    RenderManagerPause renderManager;
    BlinkingText textPause;
    sf::RectangleShape buttonContinueGame;
    sf::RectangleShape buttonSaveGame;
    sf::RectangleShape bgShape;
    sf::Texture * bgTexture;
    sf::Font font;
};

#endif //UNTITLED4_GAMESTATEPAUSE_H
