#include <iostream>
#include "../headers/Game.h"
#include "../headers/GameState.h"

class GameState;

void Game::GameLoop() {
    while (this->Window.isOpen()){
        if (GetState() != nullptr) {
            GetState()->StateRealization();
            GetState()->HandleInput();
            GetState()->Update();
        }
    }
}

GameState *Game::GetState() {
    return (this->States.empty()) ? nullptr : this->States.top();
}

void Game::PushState(GameState *state) {
    this->States.push(state);
}

void Game::PopState() {
    delete this->States.top();
    this->States.pop();
}

void Game::ChangeState(GameState *state) {
    if(!this->States.empty()){
        PopState();
    }
    PushState(state);
}

Game::Game() {
    //TODO в настройках можно редачить размер поля
    Window.create(sf::VideoMode(500, 600), "Game");
    Window.setFramerateLimit(50);
    TextureMnr.LoadTexture(TX_MENU_BG, MENU_BG_TEXTURE);
}

Game::~Game() {
    std::cout<<"Game destructor"<<std::endl;
    while(!States.empty()){ PopState();}
}
