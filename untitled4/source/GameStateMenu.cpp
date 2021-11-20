#include "../headers/GameStateMenu.h"

void GameStateMenu::HandleInput() {
    sf::Event event;
    while (Game_->Window.pollEvent(event)){
        switch (event.type) {
            case sf::Event::Closed: {
                Game_->Window.close();
                break;
            }
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Escape: {
                        Game_->Window.close();
                        break;
                    }
                    case sf::Keyboard::Space: {
                        LoadGame();
                        break;
                    }
                }
                break;
            }
            default:{
                break;
            }
        }
    }
}

void GameStateMenu::StateRealization() {
    RenderMnr.Draw();
}

void GameStateMenu::Update() {
    Game_->Window.display();
    Game_->Window.clear();
}

void GameStateMenu::LoadGame() {
    Game_->pushState(new GameStatePlaying(Game_, Game_->Window, Game_->TextureMnr));
}

GameStateMenu::~GameStateMenu() {
    std::cout<<"Game stateMenu destructor\n";
}

void GameStateMenu::RenderManagerMenu::Draw() {
    DrawBg();
}

void GameStateMenu::RenderManagerMenu::DrawBg() {
    MenuBg.setTexture(TextureMnr.getTexture(TX_MENU_BG));
    WindowLink.draw(MenuBg);
}

void GameStateMenu::RenderManagerMenu::DrawMenu() {
    //TODO прорисовать меню
}
