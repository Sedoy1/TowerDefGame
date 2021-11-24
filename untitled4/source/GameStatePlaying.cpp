#include "../headers/GameStatePlaying.h"
#include <memory>

void GameStatePlaying::StateRealization() {
    LogicEvent.GameRealization();
    if(LogicEvent.IsPlayerAlive()) {
        spawnerManager.UpdateWaves();
        RenderMnr.Draw();
        if(spawnerManager.GetWaveState()){
            Win();
        }
    }
    else{
        GameOver();
    }

}

void GameStatePlaying::HandleInput() {
    sf::Event event;
    while(this->Game_->Window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
            {
                Game_->Window.close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape) this->Game_->Window.close();
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    int xPosition = event.mouseButton.x;
                    int yPosition = event.mouseButton.y;
                    if (buttonPauseContinue.getGlobalBounds().contains(xPosition, yPosition)){
                        Pause();
                    }
                    for(int btnNumber = 0; btnNumber<buttonsWeapon.size(); btnNumber++){
                        if(buttonsWeapon[btnNumber].getGlobalBounds().contains(xPosition, yPosition)){
                            sf::IntRect bound(50, 0, 50, 50);
                            buttonsWeapon[btnNumber].setTextureRect(bound);
                            selectedCannonId = btnNumber + 1;
                            break;
                        }
                        else{
                            sf::IntRect bound(0, 0, 50, 50);
                            buttonsWeapon[btnNumber].setTextureRect(bound);
                        }
                    }
                }
                Coordinate position(event.mouseButton.x/50, event.mouseButton.y/50);
                if(gameField.IsTileBuildable(position)){
                    switch (selectedCannonId) {
                        case NoCannon: {
                            break;
                        }
                        case CannonBlue: {
                            gameField.SetBusy(true, position);
                            spawnerManager.CreateWeaponCannonBlue(position);
                            selectedCannonId = NoCannon;
                            break;
                        }
                        case CannonOrange: {
                            gameField.SetBusy(true, position);
                            spawnerManager.CreateWeaponCannonOrange(position);
                            selectedCannonId = NoCannon;
                            break;
                        }
                        case CannonBlack: {
                            gameField.SetBusy(true, position);
                            spawnerManager.CreateWeaponCannonBlack(position);
                            selectedCannonId = NoCannon;
                            break;
                        }
                    }
                }
            }

            default: break;
        }
    }
}

void GameStatePlaying::Update() {
    Game_->Window.display();
    Game_->Window.clear();
}

GameStatePlaying::GameStatePlaying(Game *game, sf::RenderWindow &window, TextureManager &newTextureManager): GameState(game),
                                                                                                     RenderMnr(
                                                                                                             window,
                                                                                                             newTextureManager,
                                                                                                             Enemies,
                                                                                                             player,
                                                                                                             gameField,
                                                                                                             buttonPauseContinue,
                                                                                                             buttonSave,
                                                                                                             FriendObjects,
                                                                                                             buttonsWeapon,
                                                                                                             labelChoiceWeapons, healthInfo, healthSprite),
                                                                                                             spawnerManager(newTextureManager), globalTextureManager(newTextureManager){
    LoadField();
    InitPlayer();
    InitButtons();
    InitHealth();
    LogicEvent.SetPlayableRules(enemyPath, Enemies, player, FriendObjects, gameField, healthInfo);
    spawnerManager.InitSpawnerOption(Enemies, &enemyPath.begin()->second, FriendObjects);
}

GameStatePlaying::~GameStatePlaying() {
    std::cout<<"Destructor Game state Playing"<<std::endl;
    // clear mem from enemies
    std::cout<<"end"<<std::endl;
}

void GameStatePlaying::InitPlayer() {
    player.InitPlayer(RenderMnr.GetTexture(TX_PLAYER), enemyPath.rbegin()->second);
}


void GameStatePlaying::RenderManagerPlay::DrawField() {
    for(GameField::Iterator iterator = gameField->Begin(); iterator != gameField->End(); iterator ++){
        WindowLink.draw(iterator.GetTile().GetTile());
    }
}


void GameStatePlaying::LoadField() {
    gameField.InitField();
    for(GameField::Iterator iterator = gameField.Begin(); iterator != gameField.End(); iterator ++){
        int id = iterator.GetTile().tileType;
        sf::Texture & texture = globalTextureManager.getTexture(TexturesID(id));
        iterator.GetTile().GetTile().setTexture(texture);
        iterator.GetTile().GetTile().setPosition(iterator.coordinates.x * RenderManagerPlay::TILE_WIDTH,
                                              iterator.coordinates.y * RenderManagerPlay::TILE_HEIGHT);
    }
    enemyPath = *gameField.ComputeEnemiesPath();
}


void GameStatePlaying::RenderManagerPlay::Draw() {
    DrawField();
    DrawFriendsObjects();
    DrawEnemies();
    DrawPlayer();
    DrawButtons();
    DrawHealth();
}


void GameStatePlaying::RenderManagerPlay::DrawEnemies() {
    for(auto object: *enemyVector)
        WindowLink.draw(object->GetSprite());
}

unsigned int GameStatePlaying::RenderManagerPlay::TILE_WIDTH = 50;
unsigned int GameStatePlaying::RenderManagerPlay::TILE_HEIGHT = 50;

void GameStatePlaying::RenderManagerPlay::LoadObjectsTexture() {
    textureManager.LoadTexture(TX_BLACK_GHOST, BLACK_GHOST_TEXTURE);
    textureManager.LoadTexture(TX_WHITE_GHOST, WHITE_GHOST_TEXTURE);
    textureManager.LoadTexture(TX_RED_GHOST, RED_GHOST_TEXTURE);
    textureManager.LoadTexture(TX_BROWN_GHOST, BROWN_GHOST_TEXTURE);
    textureManager.LoadTexture(TX_PLAYER, PLAYER_TEXTURE);
    textureManager.LoadTexture(TX_BLUE_CANNON, CANNON_BLUE_TEXTURE);
    textureManager.LoadTexture(TX_ORANGE_CANNON, CANNON_ORANGE_TEXTURE);
    textureManager.LoadTexture(TX_BLACK_CANNON, CANNON_BLACK_TEXTURE);
    textureManager.LoadTexture(TX_HEALTH, HEALTH_TEXTURE);
}

GameStatePlaying::RenderManagerPlay::~RenderManagerPlay() {
    std::cout<<"Destructor renderManager Play\n";
    std::cout<<"end renderManager play\n";
}

void GameStatePlaying::RenderManagerPlay::DrawPlayer() {
    WindowLink.draw(player->GetSprite());
}

void GameStatePlaying::RenderManagerPlay::LoadFieldTexture() {
    textureManager.LoadTexture(TX_GRASS, GRASS_TEXTURE);
    textureManager.LoadTexture(TX_START, START_TEXTURE);
    textureManager.LoadTexture(TX_PLAIN, PLAIN_TEXTURE);
    textureManager.LoadTexture(TX_TRAIL, TRAIL_TEXTURE);
    textureManager.LoadTexture(TX_FINISH, FINISH_TEXTURE);
}

void GameStatePlaying::RenderManagerPlay::LoadButtonsTexture() {
    textureManager.LoadTexture(TX_BTN_PAUSE, BUTTON_PAUSE_CONTINUE);
    textureManager.LoadTexture(TX_BTN_SAVE, BUTTON_SAVE);
    textureManager.LoadTexture(TX_BG_BUTTONS, BG_BUTTONS);
    textureManager.LoadTexture(TX_BTN_WEAPON_BLUE, BUTTON_CANNON_BLUE);
    textureManager.LoadTexture(TX_BTN_WEAPON_ORANGE, BUTTON_CANNON_ORANGE);
    textureManager.LoadTexture(TX_BTN_WEAPON_BLACK, BUTTON_CANNON_BLACK);
}

void GameStatePlaying::RenderManagerPlay::DrawButtons() {
    WindowLink.draw(*buttonSave);
    WindowLink.draw(*buttonPause);
    WindowLink.draw(*labelWeaponsButtons);
    for(auto btn: *vectorButtonsWeapons)
        WindowLink.draw(btn);
}

void GameStatePlaying::RenderManagerPlay::DrawFriendsObjects() {
    for(auto weapon : *friendVector)
        WindowLink.draw(weapon->GetSprite());
}

GameStatePlaying::RenderManagerPlay::RenderManagerPlay(sf::RenderWindow &window, TextureManager &textureManager,
                                                       std::vector<std::shared_ptr<Enemy>> &enemyVector, Player &player,
                                                       GameField &gameField,
                                                       sf::RectangleShape &buttonPause, sf::RectangleShape &buttonSave,
                                                       std::vector<std::shared_ptr<FriendObject>> &friendVector,
                                                       std::vector<sf::RectangleShape> &buttonsWeapons,
                                                       sf::RectangleShape &labelButtons, sf::Text & healthText, sf::Sprite & health) : RenderManager(window, textureManager){
    LoadFieldTexture();
    LoadObjectsTexture();
    LoadButtonsTexture();
    this->enemyVector = &enemyVector;
    this->player = &player;
    this->gameField = &gameField;
    this->buttonSave = &buttonSave;
    this->buttonPause = &buttonPause;
    this->friendVector = &friendVector;
    this->healthText = &healthText;
    this->health = &health;
    labelWeaponsButtons = &labelButtons;
    vectorButtonsWeapons = &buttonsWeapons;
}

void GameStatePlaying::RenderManagerPlay::DrawHealth() {
    WindowLink.draw(*healthText);
    WindowLink.draw(*health);
}

void GameStatePlaying::GameOver() {
    Game_->changeState(new GameStateGameEnd(Game_, Game_->Window, Game_->TextureMnr, LOOSE));
}

void GameStatePlaying::Win() {
    Game_->changeState(new GameStateGameEnd(Game_, Game_->Window, Game_->TextureMnr, WIN));
}

void GameStatePlaying::InitButtons() {
    buttonPauseContinue.setSize(sf::Vector2f (50, 50));
    buttonPauseContinue.setTexture(&globalTextureManager.getTexture(TX_BTN_PAUSE));
    sf::FloatRect buttonRect = buttonPauseContinue.getLocalBounds();
    buttonPauseContinue.setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
    buttonPauseContinue.setPosition(SCREEN_WIDTH - 75, 25);
    sf::IntRect bound(0, 0, 50, 50);
    buttonPauseContinue.setTextureRect(bound);

    buttonSave.setSize(sf::Vector2f (50, 50));
    buttonSave.setTexture(&globalTextureManager.getTexture(TX_BTN_SAVE));
    buttonRect = buttonSave.getLocalBounds();
    buttonSave.setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
    buttonSave.setPosition(SCREEN_WIDTH - 25, 25);

    labelChoiceWeapons.setSize(sf::Vector2f (SCREEN_WIDTH, SCREEN_HEIGHT - 500));
    labelChoiceWeapons.setTexture(&globalTextureManager.getTexture(TX_BG_BUTTONS));
    buttonRect = labelChoiceWeapons.getGlobalBounds();
    labelChoiceWeapons.setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
    labelChoiceWeapons.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT - 50);

    sf::FloatRect labelRect = labelChoiceWeapons.getGlobalBounds();
    int widthSize = 90;
    int heightSize = 80;
    int spaceBtn = widthSize;
    for(int i=0; i<buttonsWeapon.size(); i++){
        buttonsWeapon[i].setSize(sf::Vector2f (widthSize, heightSize));
        buttonRect = buttonsWeapon[i].getGlobalBounds();
        buttonsWeapon[i].setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
        buttonsWeapon[i].setPosition(labelRect.left + (widthSize/2.0f) * (i + 1) + spaceBtn* (i+1), labelRect.top + 10 + heightSize/2.0f);
    }
    buttonsWeapon[0].setTexture(&globalTextureManager.getTexture(TX_BTN_WEAPON_BLUE));
    buttonsWeapon[0].setTextureRect(bound);
    buttonsWeapon[1].setTexture(&globalTextureManager.getTexture(TX_BTN_WEAPON_ORANGE));
    buttonsWeapon[1].setTextureRect(bound);
    buttonsWeapon[2].setTexture(&globalTextureManager.getTexture(TX_BTN_WEAPON_BLACK));
    buttonsWeapon[2].setTextureRect(bound);
}

void GameStatePlaying::Pause() {
    //TODO продумать паузу по другому, тк при выполнении цикла gamelogic отстает
    sf::IntRect bound(50, 0, 50, 50);
    buttonPauseContinue.setTextureRect(bound);
    Game_->Window.clear();
    RenderMnr.Draw();
    Game_->Window.display();
    auto bgTexture = new sf::Texture;
    bgTexture->create(SCREEN_WIDTH, SCREEN_HEIGHT);
    bgTexture->update(Game_->Window);
    Game_->pushState(new GameStatePause(Game_, Game_->Window, Game_->TextureMnr, bgTexture));
    bound.left -= 50;
    buttonPauseContinue.setTextureRect(bound);
}

void GameStatePlaying::InitHealth() {
    font.loadFromFile(TEXT_FONT);
    healthInfo.setFont(font);
    healthInfo.setCharacterSize(32);
    healthInfo.setFillColor(sf::Color::Black);
    healthInfo.setStyle(sf::Text::Style::Bold);
    healthInfo.setString(std::to_string(player.GetHealth()));
    healthInfo.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT - labelChoiceWeapons.getSize().y - healthInfo.getLocalBounds().width);
    healthSprite.setScale(0.1f, 0.1f);
    healthSprite.setTexture(globalTextureManager.getTexture(TX_HEALTH));
    sf::FloatRect textRect = healthInfo.getGlobalBounds();
    healthSprite.setPosition(sf::Vector2f (textRect.left + textRect.width, textRect.top - textRect.height - 5));
}
