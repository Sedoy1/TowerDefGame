#include "../headers/GameStateGameEnd.h"
#include "../headers/GameStatePlaying.h"

void GameStateGameEnd::StateRealization() {
    renderManger.Draw(textGameResult, buttonRestart, buttonBackMenu, buttonExit);
}

void GameStateGameEnd::HandleInput() {
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

            case sf::Event::MouseMoved:{
                int xPosition = event.mouseMove.x;
                int yPosition = event.mouseMove.y;
                if(buttonRestart.getGlobalBounds().contains(xPosition, yPosition)){
                    sf::IntRect bound(100, 0, 100, 50);
                    buttonRestart.setTextureRect(bound);
                }
                else if(buttonBackMenu.getGlobalBounds().contains(xPosition, yPosition)){
                    sf::IntRect bound(100, 0, 100, 50);
                    buttonBackMenu.setTextureRect(bound);
                }
                else if(buttonExit.getGlobalBounds().contains(xPosition, yPosition)){
                    sf::IntRect bound(100, 0, 100, 50);
                    buttonExit.setTextureRect(bound);
                }
                else{
                    sf::IntRect bound(0, 0, 100, 50);
                    buttonRestart.setTextureRect(bound);
                    buttonBackMenu.setTextureRect(bound);
                    buttonExit.setTextureRect(bound);
                }
            }
            default:{
                break;
            }
        }
    }
}

void GameStateGameEnd::Update() {
    Game_->Window.display();
    Game_->Window.clear();
}

GameStateGameEnd::~GameStateGameEnd() {

}

void GameStateGameEnd::RestartGame() {
    Game_->changeState(new GameStatePlaying(Game_, Game_->Window, Game_->TextureMnr));
}

void GameStateGameEnd::InitText(int endID) {
    textGameResult.setFont(renderManger.font);
    std::string gameResult;
    (endID == LOOSE)? gameResult="Game Over":gameResult="You win!";
    textGameResult.setString(gameResult);
    textGameResult.setCharacterSize(32);
    textGameResult.setFillColor(sf::Color::White);
    textGameResult.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = textGameResult.getLocalBounds();
    textGameResult.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top  + textRect.height/2.0f);
    textGameResult.setPosition(sf::Vector2f(SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH / 2.0f));
}

void GameStateGameEnd::InitButtons() {
    unsigned int IndentY = SCREEN_HEIGHT * 0.15f;
    sf::FloatRect textRect = textGameResult.getLocalBounds();

    buttonRestart.setSize(sf::Vector2f (textRect.width, SCREEN_HEIGHT / 10.0f));
    buttonRestart.setTexture(&renderManger.TextureMnr.getTexture(TX_BTN_RESTART));
    sf::FloatRect buttonRect = buttonRestart.getLocalBounds();
    buttonRestart.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonRestart.setPosition(sf::Vector2f (textGameResult.getPosition().x, textGameResult.getPosition().y + IndentY));
    sf::IntRect bound(0, 0, 100, 50);
    buttonRestart.setTextureRect(bound);

    buttonBackMenu.setSize(sf::Vector2f (textRect.width, SCREEN_HEIGHT / 10.0f));
    buttonBackMenu.setTexture(&renderManger.TextureMnr.getTexture(TX_BTN_MENU));
    buttonRect = buttonBackMenu.getLocalBounds();
    buttonBackMenu.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonBackMenu.setPosition(sf::Vector2f (buttonRestart.getPosition().x, buttonRestart.getPosition().y + IndentY));
    buttonBackMenu.setTextureRect(bound);

    buttonExit.setSize(sf::Vector2f (textRect.width, SCREEN_HEIGHT / 10.0f));
    buttonExit.setTexture(&renderManger.TextureMnr.getTexture(TX_BTN_EXIT));
    buttonRect = buttonExit.getLocalBounds();
    buttonExit.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonExit.setPosition(sf::Vector2f (buttonBackMenu.getPosition().x, buttonBackMenu.getPosition().y + IndentY));
    buttonExit.setTextureRect(bound);
}

void GameStateGameEnd::Back2Menu() {
    Game_->popState();
}

void GameStateGameEnd::RenderManagerGameOver::Draw(sf::Text & newTextGameOver, sf::RectangleShape & newButtonRestart,
                                                    sf::RectangleShape &newButtonMenu,
                                                    sf::RectangleShape &newButtonExit) {
    DrawText(newTextGameOver);
    DrawButtons(newButtonRestart, newButtonMenu, newButtonExit);
}

void GameStateGameEnd::RenderManagerGameOver::DrawText(sf::Text & newTextGameOver) {
    WindowLink.draw(newTextGameOver);
}

void GameStateGameEnd::RenderManagerGameOver::DrawButtons(sf::RectangleShape &newButtonRestart, sf::RectangleShape &newButtonMenu,
                                                           sf::RectangleShape &newButtonExit) {
    WindowLink.draw(newButtonRestart);
    WindowLink.draw(newButtonMenu);
    WindowLink.draw(newButtonExit);
}
