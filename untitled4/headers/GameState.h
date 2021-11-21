#ifndef UNTITLED4_GAMESTATE_H
#define UNTITLED4_GAMESTATE_H
#include "Game.h"
#include "RenderManager.h"
#include "iostream"

class GameState{
    public:
    Game * Game_;
    GameState(Game * game){ Game_ = game;};
    virtual ~GameState(){std::cout<<"State destructor\n";};
    virtual void StateRealization() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
};
#endif //UNTITLED4_GAMESTATE_H
