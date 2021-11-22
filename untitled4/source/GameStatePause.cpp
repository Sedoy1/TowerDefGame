#include "../headers/GameStatePause.h"

void GameStatePause::InitText() {
    font.loadFromFile(TEXT_FONT);
    textPause.setFont(font);
    std::string gameResult;
    gameResult="Pause";
    textPause.setString(gameResult);
    textPause.setCharacterSize(32);
    textPause.setFillColor(sf::Color::White);
    textPause.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = textPause.getLocalBounds();
    textPause.setOrigin(textRect.left + textRect.width / 2.0f,
                             textRect.top  + textRect.height/2.0f);
    textPause.setPosition(sf::Vector2f(SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH / 2.0f));
}

void GameStatePause::Update() {
    Game_->Window.display();
    Game_->Window.clear();
}

void GameStatePause::StateRealization() {
    renderManager.Draw(textPause, buttonContinueGame, buttonSaveGame, bgShape);
}

void GameStatePause::HandleInput() {
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
                }
                break;
            }
            case sf::Event::MouseButtonPressed:{
                if(event.mouseButton.button == sf::Mouse::Left) {
                    int xPosition = event.mouseButton.x;
                    int yPosition = event.mouseButton.y;
                    if(buttonSaveGame.getGlobalBounds().contains(xPosition, yPosition)){
                        SaveGame();
                        return;
                    }
                    else if(buttonContinueGame.getGlobalBounds().contains(xPosition, yPosition)){
                        ContinueGame();
                        return;
                    }
                }
                break;
            }
        }
    }
}

void GameStatePause::SaveGame() {
    //TODO прописать сохранени здесь
}

void GameStatePause::ContinueGame() {
    Game_->popState();
}

void GameStatePause::InitButtons() {
    buttonContinueGame.setSize(sf::Vector2f (50, 50));
    buttonContinueGame.setTexture(&renderManager.TextureMnr.getTexture(TX_BTN_CONTINUE));
    sf::FloatRect buttonRect = buttonContinueGame.getLocalBounds();
    buttonContinueGame.setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
    buttonContinueGame.setPosition(SCREEN_WIDTH - 75, 25);

    buttonSaveGame.setSize(sf::Vector2f (50, 50));
    buttonSaveGame.setTexture(&renderManager.TextureMnr.getTexture(TX_BTN_SAVE));
    buttonRect = buttonSaveGame.getLocalBounds();
    buttonSaveGame.setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
    buttonSaveGame.setPosition(SCREEN_WIDTH - 25, 25);
}

void GameStatePause::InitBg(sf::Texture *newBgTexture) {
    bgTexture = newBgTexture;
    bgShape.setSize(sf::Vector2f (SCREEN_WIDTH, SCREEN_HEIGHT));
    bgShape.setTexture(bgTexture);
}

void GameStatePause::RenderManagerPause::Draw(sf::Text &newTextPause, sf::RectangleShape &newButtonContinue,
                                              sf::RectangleShape &newButtonSave, sf::RectangleShape &bgShape) {
    DrawBg(bgShape);
    DrawButtons(newButtonContinue, newButtonSave);
    DrawText(newTextPause);
}

void GameStatePause::RenderManagerPause::LoadTexture() {
    TextureMnr.LoadTexture(TX_BTN_CONTINUE, BUTTON_CONTINUE);
    TextureMnr.LoadTexture(TX_BTN_SAVE, BUTTON_SAVE);
}

void GameStatePause::RenderManagerPause::DrawButtons(sf::RectangleShape &newButtonContinue,
                                                     sf::RectangleShape &newButtonSave) {
    WindowLink.draw(newButtonSave);
    WindowLink.draw(newButtonContinue);

}

void GameStatePause::RenderManagerPause::DrawText(sf::Text &newTextPause) {
    WindowLink.draw(newTextPause);
}

void GameStatePause::RenderManagerPause::DrawBg(sf::RectangleShape &newBgShape) {
    WindowLink.draw(newBgShape);
}


