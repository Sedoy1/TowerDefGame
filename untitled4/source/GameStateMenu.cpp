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
                        StartGame();
                        return;
                    }
                }
                break;
            }
            case sf::Event::MouseMoved:{
                float x = event.mouseMove.x;
                float y = event.mouseMove.y;
                sf::IntRect bound (100, 0, 100, 50);
                if(buttonLoadGame.getGlobalBounds().contains(x,y)){
                    buttonLoadGame.setTextureRect(bound);
                }
                else if(buttonStartGame.getGlobalBounds().contains(x,y)){
                    buttonStartGame.setTextureRect(bound);
                }
                else if(buttonOptions.getGlobalBounds().contains(x,y)){
                    buttonOptions.setTextureRect(bound);
                }
                else if(buttonExit.getGlobalBounds().contains(x,y)){
                    buttonExit.setTextureRect(bound);
                }
                else{
                    bound.left -= 100;
                    buttonStartGame.setTextureRect(bound);
                    buttonLoadGame.setTextureRect(bound);
                    buttonOptions.setTextureRect(bound);
                    buttonExit.setTextureRect(bound);
                }
            }
            case sf::Event::MouseButtonPressed:{
                if(event.mouseButton.button != sf::Mouse::Left)
                    continue;
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;
                if(buttonLoadGame.getGlobalBounds().contains(x,y)){
                    LoadGame();
                }
                else if(buttonStartGame.getGlobalBounds().contains(x,y)){
                    StartGame();
                }
                else if(buttonOptions.getGlobalBounds().contains(x,y)){
                    Options();
                }
                else if(buttonExit.getGlobalBounds().contains(x,y)){
                    Game_->Window.close();
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

void GameStateMenu::StartGame() {
    Game_->pushState(new GameStatePlaying(Game_, Game_->Window, Game_->TextureMnr));
}

GameStateMenu::~GameStateMenu() {
    std::cout<<"Game stateMenu destructor\n";
}

GameStateMenu::GameStateMenu(Game *game, sf::RenderWindow &window, TextureManager &textureManager): GameState(game),
renderManager(window,textureManager, bgSprite, textMenu, buttonStartGame, buttonOptions, buttonLoadGame, buttonExit) {
    InitBg();
    InitText();
    InitButtons();
}

void GameStateMenu::InitBg() {
    Coordinate coord(0,0);
    bgSprite.InitSprite(renderManager.GetTexture(TX_MENU_BG), coord, 500, 600);
    Animation animation(10.0f);
    bgSprite.SetAnimation(animation);
}

void GameStateMenu::InitButtons() {
    unsigned int IndentY = SCREEN_HEIGHT * 0.15f;
    float width = SCREEN_WIDTH / 4.0f;
    float height = SCREEN_HEIGHT / 10.0f;
    sf::IntRect bound(0, 0, 100, 50);


    buttonStartGame.setSize(sf::Vector2f (width, height));
    buttonStartGame.setTexture(&renderManager.GetTexture(TX_BTN_START));
    sf::FloatRect buttonRect = buttonStartGame.getLocalBounds();
    buttonStartGame.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonStartGame.setPosition(sf::Vector2f (textMenu.getPosition().x, textMenu.getPosition().y + IndentY));
    buttonStartGame.setTextureRect(bound);

    buttonLoadGame.setSize(sf::Vector2f (width, height));
    buttonLoadGame.setTexture(&renderManager.GetTexture(TX_BTN_LOAD_GAME));
    buttonRect = buttonLoadGame.getLocalBounds();
    buttonLoadGame.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonLoadGame.setPosition(sf::Vector2f (textMenu.getPosition().x, buttonStartGame.getPosition().y + IndentY));
    buttonLoadGame.setTextureRect(bound);

    buttonOptions.setSize(sf::Vector2f (width, height));
    buttonOptions.setTexture(&renderManager.GetTexture(TX_BTN_OPTIONS));
    buttonRect = buttonOptions.getLocalBounds();
    buttonOptions.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonOptions.setPosition(sf::Vector2f (textMenu.getPosition().x, buttonLoadGame.getPosition().y + IndentY));
    buttonOptions.setTextureRect(bound);

    buttonExit.setSize(sf::Vector2f (width, height));
    buttonExit.setTexture(&renderManager.GetTexture(TX_BTN_EXIT));
    buttonRect = buttonExit.getLocalBounds();
    buttonExit.setOrigin(buttonRect.left + buttonRect.width/2.0f, buttonRect.top + buttonRect.height/2.0f);
    buttonExit.setPosition(sf::Vector2f (textMenu.getPosition().x, buttonOptions.getPosition().y + IndentY));
    buttonExit.setTextureRect(bound);
}

void GameStateMenu::InitText() {
    std::string gameResult;
    gameResult="Menu";
    textMenu.InitText(gameResult);
    sf::FloatRect textRect = textMenu.getLocalBounds();
    textMenu.setOrigin(textRect.left + textRect.width / 2.0f,
                        textRect.top  + textRect.height/2.0f);
    textMenu.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 3.0f));
}

void GameStateMenu::LoadGame() {
    //TODO загрузить сохраненную игру
}

void GameStateMenu::Options() {
    //TODO сделать типа опции
}

void GameStateMenu::RenderManagerMenu::Draw() {
    DrawBg();
    DrawText();
    DrawButtons();
}

void GameStateMenu::RenderManagerMenu::DrawBg() {
    bgSprite->Update();
    WindowLink.draw(*bgSprite);
}

GameStateMenu::RenderManagerMenu::RenderManagerMenu(sf::RenderWindow &window, TextureManager &textureManager,
                                                    AnimationSprite &newBgSprite,
                                                    BlinkingText &newTextMenu, sf::RectangleShape &newButtonStartGame,
                                                    sf::RectangleShape &newButtonOptions,
                                                    sf::RectangleShape &newButtonLoadGame,
                                                    sf::RectangleShape &newButtonExit) : RenderManager(window, textureManager) {
    LoadTextures();
    bgSprite = &newBgSprite;
    textMenu = &newTextMenu;
    buttonStartGame = &newButtonStartGame;
    buttonOptions = &newButtonOptions;
    buttonLoadGame = &newButtonLoadGame;
    buttonExit = &newButtonExit;
}

void GameStateMenu::RenderManagerMenu::DrawButtons() {
    WindowLink.draw(*buttonStartGame);
    WindowLink.draw(*buttonOptions);
    WindowLink.draw(*buttonLoadGame);
    WindowLink.draw(*buttonExit);
}

void GameStateMenu::RenderManagerMenu::DrawText() {
    textMenu->Update();
    if(textMenu->GetBlinkState())
    WindowLink.draw(*textMenu);
}

void GameStateMenu::RenderManagerMenu::LoadTextures() {
    textureManager.LoadTexture(TX_BTN_LOAD_GAME, BUTTON_LOAD_GAME);
    textureManager.LoadTexture(TX_BTN_EXIT, BUTTON_EXIT);
    textureManager.LoadTexture(TX_BTN_OPTIONS, BUTTON_OPTIONS);
    textureManager.LoadTexture(TX_BTN_START, BUTTON_PLAY);
}
