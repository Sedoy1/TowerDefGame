#include "../headers/GameStateGameOver.h"
#include "../headers/GameStatePlaying.h"

void GameStateGameOver::StateRealization() {
    renderManger.Draw(textGameOver, buttonRestart, buttonBackMenu, buttonExit);
}

void GameStateGameOver::HandleInput() {
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
                    if(buttonRestart.getGlobalBounds().contains(xPosition, yPosition)){
                        RestartGame();
                        return;
                    }
                    else if(buttonBackMenu.getGlobalBounds().contains(xPosition, yPosition)){
                        Back2Menu();
                        return;
                    }
                    else if(buttonExit.getGlobalBounds().contains(xPosition, yPosition)){
                        Game_->Window.close();
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

void GameStateGameOver::Update() {
    Game_->Window.display();
    Game_->Window.clear();
}

GameStateGameOver::~GameStateGameOver() {

}

void GameStateGameOver::RestartGame() {
    Game_->changeState(new GameStatePlaying(Game_, Game_->Window, Game_->TextureMnr));
}

void GameStateGameOver::InitText() {
    textGameOver.setFont(renderManger.font);
    textGameOver.setString("Game Over");
    textGameOver.setCharacterSize(32);
    textGameOver.setFillColor(sf::Color::White);
    textGameOver.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = textGameOver.getLocalBounds();
    textGameOver.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    textGameOver.setPosition(sf::Vector2f(SCREEN_HEIGHT/2.0f,SCREEN_WIDTH/2.0f));
}

void GameStateGameOver::InitButtons() {
    unsigned int IndentY = SCREEN_HEIGHT * 0.15f;
    sf::FloatRect textRect = textGameOver.getLocalBounds();

    buttonRestart.setSize(sf::Vector2f (textRect.width, SCREEN_HEIGHT / 10.0f));
    buttonRestart.setTexture(&renderManger.TextureMnr.getTexture(TX_BTN_RESTART));
    sf::FloatRect buttonRect = buttonRestart.getLocalBounds();
    buttonRestart.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonRestart.setPosition(sf::Vector2f (textGameOver.getPosition().x, textGameOver.getPosition().y + IndentY));

    buttonBackMenu.setSize(sf::Vector2f (textRect.width, SCREEN_HEIGHT / 10.0f));
    buttonBackMenu.setTexture(&renderManger.TextureMnr.getTexture(TX_BTN_MENU));
    buttonRect = buttonBackMenu.getLocalBounds();
    buttonBackMenu.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonBackMenu.setPosition(sf::Vector2f (buttonRestart.getPosition().x, buttonRestart.getPosition().y + IndentY));

    buttonExit.setSize(sf::Vector2f (textRect.width, SCREEN_HEIGHT / 10.0f));
    buttonExit.setTexture(&renderManger.TextureMnr.getTexture(TX_BTN_EXIT));
    buttonRect = buttonExit.getLocalBounds();
    buttonExit.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonExit.setPosition(sf::Vector2f (buttonBackMenu.getPosition().x, buttonBackMenu.getPosition().y + IndentY));
}

void GameStateGameOver::Back2Menu() {
    Game_->popState();
}

void GameStateGameOver::RenderManagerGameOver::Draw(sf::Text & newTextGameOver, sf::RectangleShape & newButtonRestart,
                                                    sf::RectangleShape &newButtonMenu,
                                                    sf::RectangleShape &newButtonExit) {
    DrawText(newTextGameOver);
    DrawButtons(newButtonRestart, newButtonMenu, newButtonExit);
}

void GameStateGameOver::RenderManagerGameOver::DrawText(sf::Text & newTextGameOver) {
    WindowLink.draw(newTextGameOver);
}

void GameStateGameOver::RenderManagerGameOver::DrawButtons(sf::RectangleShape &newButtonRestart, sf::RectangleShape &newButtonMenu,
                                                           sf::RectangleShape &newButtonExit) {
    WindowLink.draw(newButtonRestart);
    WindowLink.draw(newButtonMenu);
    WindowLink.draw(newButtonExit);
}
