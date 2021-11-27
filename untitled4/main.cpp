#include "iostream"
#include "headers/Game.h"
#include "headers/GameStateMenu.h"

int main()
{
    Game game;
    game.PushState(new GameStateMenu(&game, game.Window, game.TextureMnr));
    game.GameLoop();
    return 0;
}