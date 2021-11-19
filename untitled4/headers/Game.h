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
    void gameLoop();
    void pushState(GameState * state);
    void popState();
    void changeState(GameState * state);
    GameState * getState();
    Game();
    ~Game();
};

#endif //UNTITLED4_GAME_H
