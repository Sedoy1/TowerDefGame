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
                        return;
                    }
                }
                break;
            }
            default:{
                break;
            }
        }
    }
    return;
}

void GameStateMenu::StateRealization() {
    renderManager.Draw();
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
    DrawMenu();
}

void GameStateMenu::RenderManagerMenu::DrawBg() {
    MenuBg.setTexture(TextureMnr.getTexture(TX_MENU_BG));
    WindowLink.draw(MenuBg);
}

void GameStateMenu::RenderManagerMenu::DrawMenu() {
    //TODO прорисовать меню
    sf::Text text;
    text.setFont(font);
    text.setString("Test menu");
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(250, 250);
    WindowLink.draw(text);
}
