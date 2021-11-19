#ifndef UNTITLED4_GAMESTATEMENU_H
#define UNTITLED4_GAMESTATEMENU_H
#include "GameState.h"
#include "RenderManagerMenu.h"
#include "GameStatePlaying.h"

class GameStateMenu : public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    GameStateMenu(Game * game, sf::RenderWindow &window, TextureManager & textureManager): GameState(game), RenderMnr(window, textureManager) {}
    ~GameStateMenu();
private:
    void LoadGame();
    RenderManagerMenu RenderMnr;
};


#endif //UNTITLED4_GAMESTATEMENU_H
