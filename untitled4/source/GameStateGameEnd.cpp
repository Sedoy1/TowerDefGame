#include "../headers/GameStateGameEnd.h"
#include "../headers/GameStatePlaying.h"

void GameStateGameEnd::StateRealization() {
    renderManger.Draw(textGameResult, buttonRestart, buttonBackMenu, buttonExit, bgTexture);
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
    Game_->ChangeState(new GameStatePlaying(Game_, Game_->Window, Game_->TextureMnr));
}

void GameStateGameEnd::InitText(int endID) {
    textGameResult.setFont(renderManger.font);
    std::string gameResult;
    (endID == LOOSE)? gameResult="Game Over":gameResult="You win!";
    textGameResult.setString(gameResult);
    textGameResult.setCharacterSize(32);
    (endID == LOOSE)? textGameResult.setFillColor(sf::Color::Blue) : textGameResult.setFillColor(sf::Color::White);
    textGameResult.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = textGameResult.getLocalBounds();
    textGameResult.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top  + textRect.height/2.0f);
    textGameResult.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f));
}

void GameStateGameEnd::InitButtons() {
    unsigned int IndentY = SCREEN_HEIGHT * 0.15f;
    float width = SCREEN_WIDTH / 4.0f;
    float height = SCREEN_HEIGHT / 10.0f;

    buttonRestart.setSize(sf::Vector2f (width, height));
    buttonRestart.setTexture(&renderManger.textureManager.GetTexture(TX_BTN_RESTART));
    sf::FloatRect buttonRect = buttonRestart.getLocalBounds();
    buttonRestart.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonRestart.setPosition(sf::Vector2f (textGameResult.getPosition().x, textGameResult.getPosition().y + IndentY));
    sf::IntRect bound(0, 0, 100, 50);
    buttonRestart.setTextureRect(bound);

    buttonBackMenu.setSize(sf::Vector2f (width, height));
    buttonBackMenu.setTexture(&renderManger.textureManager.GetTexture(TX_BTN_MENU));
    buttonRect = buttonBackMenu.getLocalBounds();
    buttonBackMenu.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonBackMenu.setPosition(sf::Vector2f (textGameResult.getPosition().x, buttonRestart.getPosition().y + IndentY));
    buttonBackMenu.setTextureRect(bound);

    buttonExit.setSize(sf::Vector2f (width, height));
    buttonExit.setTexture(&renderManger.textureManager.GetTexture(TX_BTN_EXIT));
    buttonRect = buttonExit.getLocalBounds();
    buttonExit.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonExit.setPosition(sf::Vector2f (textGameResult.getPosition().x, buttonBackMenu.getPosition().y + IndentY));
    buttonExit.setTextureRect(bound);
}

void GameStateGameEnd::Back2Menu() {
    Game_->PopState();
}

void GameStateGameEnd::InitBg(int endID) {
    bgTexture.setSize(sf::Vector2f (SCREEN_WIDTH, SCREEN_HEIGHT));
    bgTexture.setOrigin(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
    bgTexture.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
    if(endID == LOOSE){
        bgTexture.setTexture(&renderManger.textureManager.GetTexture(TX_BG_GAME_OVER));
    }
    else{
        bgTexture.setTexture(&renderManger.textureManager.GetTexture(TX_BG_GAME_WIN));
    }
}

void GameStateGameEnd::RenderManagerGameOver::Draw(sf::Text &newTextGameOver, sf::RectangleShape &newButtonRestart,
                                                   sf::RectangleShape &newButtonMenu,
                                                   sf::RectangleShape &newButtonExit,
                                                   sf::RectangleShape &newBgTexture) {
    DrawBg(newBgTexture);
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

void GameStateGameEnd::RenderManagerGameOver::LoadTexture() {
    textureManager.LoadTexture(TX_BTN_RESTART, BUTTON_RELOAD);
    textureManager.LoadTexture(TX_BTN_MENU, BUTTON_MENU);
    textureManager.LoadTexture(TX_BTN_EXIT, BUTTON_EXIT);
    textureManager.LoadTexture(TX_BG_GAME_OVER, BG_GAME_OVER);
    textureManager.LoadTexture(TX_BG_GAME_WIN, BG_GAME_WIN);
}

void GameStateGameEnd::RenderManagerGameOver::DrawBg(sf::RectangleShape &newBgTexture) {
    WindowLink.draw(newBgTexture);
}
