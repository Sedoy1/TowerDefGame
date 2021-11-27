#ifndef UNTITLED4_GAME_H
#define UNTITLED4_GAME_H
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include <stack>
#include "ElementsDefinition.h"
class GameState;

class Game{
    private:
    std::stack<GameState * > States;
    public:
    sf::RenderWindow Window;
    TextureManager TextureMnr;
    void GameLoop();
    void PushState(GameState * state);
    void PopState();
    void ChangeState(GameState * state);
    GameState * GetState();
    Game();
    ~Game();
};

#endif //UNTITLED4_GAME_H
