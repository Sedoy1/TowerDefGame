#ifndef UNTITLED4_GAMESTATEGAMEOVER_H
#define UNTITLED4_GAMESTATEGAMEOVER_H
#include "GameState.h"

class GameStateGameOver: public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    //GameStateGameOver(Game * game, sf::RenderWindow &window, TextureManager & textureManager): GameState(game), RenderMnr(window, textureManager) {}
    ~GameStateGameOver();
private:
    //RenderManagerMenu RenderMnr;
};


#endif //UNTITLED4_GAMESTATEGAMEOVER_H
