#include "iostream"
#include "headers/Game.h"
#include "headers/GameStateMenu.h"

int main()
{
    Game game;
    game.pushState(new GameStateMenu(&game, game.Window, game.TextureMnr));
    game.gameLoop();
    return 0;
}