#include <iostream>
#include "../headers/Game.h"
#include "../headers/GameState.h"

class GameState;

void Game::gameLoop() {
    while (this->Window.isOpen()){
        if (getState() != nullptr) {
            getState()->StateRealization();
            getState()->HandleInput();
            getState()->Update();
        }
    }
}

GameState *Game::getState() {
    return (this->States.empty()) ? nullptr : this->States.top();
}

void Game::pushState(GameState *state) {
    this->States.push(state);
}

void Game::popState() {
    delete this->States.top();
    this->States.pop();
}

void Game::changeState(GameState *state) {
    if(!this->States.empty()){
        popState();
    }
    pushState(state);
}

Game::Game() {
    Window.create(sf::VideoMode(500, 500), "Game");
    Window.setFramerateLimit(60);
    TextureMnr.LoadTexture(TX_MENU_BG, MENU_BG_TEXTURE);
}

Game::~Game() {
    std::cout<<"Game destructor"<<std::endl;
    while(!States.empty()){popState();}
}
