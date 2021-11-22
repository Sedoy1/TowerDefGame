#ifndef UNTITLED4_GAMESTATE_H
#define UNTITLED4_GAMESTATE_H
#include "Game.h"
#include "RenderManager.h"
#include "iostream"
#include "TextureManager.h"

class GameState{
protected:
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
public:
    Game * Game_;
    GameState(Game * game){
        Game_ = game;
        SCREEN_HEIGHT = Game_->Window.getSize().y;
        SCREEN_WIDTH = Game_->Window.getSize().x;
    };
    virtual ~GameState(){std::cout<<"State destructor\n";};
    virtual void StateRealization() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
};
#endif //UNTITLED4_GAMESTATE_H
