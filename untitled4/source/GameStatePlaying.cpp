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
                }
                Coordinate position(event.mouseButton.x/50, event.mouseButton.y/50);
                if(gameField.IsTileBuildable(position)){
                    gameField.SetBusy(true, position);
                    spawnerManager.CreateWeaponCannon(position);
                    break;
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
RenderMnr(window, newTextureManager, Enemies, player, gameField, buttonPauseContinue, buttonSave, FriendObjects),
spawnerManager(newTextureManager), textureManager(newTextureManager){
    LoadField();
    InitPlayer();
    InitButtons();
    LogicEvent.SetPlayableRules(enemyPath, Enemies, player, FriendObjects, gameField);
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
        sf::Texture & texture = textureManager.getTexture(TexturesID(id));
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
    textureManager.LoadTexture(TX_PLAYER, PLAYER_TEXTURE);
    textureManager.LoadTexture(TX_CANNON, CANNON_TEXTURE);
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
}

void GameStatePlaying::RenderManagerPlay::DrawButtons() {
    WindowLink.draw(*buttonSave);
    WindowLink.draw(*buttonPause);
}

void GameStatePlaying::RenderManagerPlay::DrawFriendsObjects() {
    for(auto weapon : *friendVector)
        WindowLink.draw(weapon->GetSprite());
}

GameStatePlaying::RenderManagerPlay::RenderManagerPlay(sf::RenderWindow &window, TextureManager &textureManager,
                                                       std::vector<std::shared_ptr<Enemy>> &enemyVector,
                                                       Player & player, GameField &gameField,
                                                       sf::RectangleShape &buttonPause, sf::RectangleShape &buttonSave,
                                                       std::vector<std::shared_ptr<FriendObject>> &friendVector): RenderManager(window, textureManager){
    this->enemyVector = &enemyVector;
    this->player = &player;
    this->gameField = &gameField;
    this->buttonSave = &buttonSave;
    this->buttonPause = &buttonPause;
    this->friendVector = &friendVector;
    LoadFieldTexture();
    LoadObjectsTexture();
    LoadButtonsTexture();
}

void GameStatePlaying::GameOver() {
    Game_->changeState(new GameStateGameEnd(Game_, Game_->Window, Game_->TextureMnr, LOOSE));
}

void GameStatePlaying::Win() {
    Game_->changeState(new GameStateGameEnd(Game_, Game_->Window, Game_->TextureMnr, WIN));
}

void GameStatePlaying::InitButtons() {
    buttonPauseContinue.setSize(sf::Vector2f (50, 50));
    buttonPauseContinue.setTexture(&textureManager.getTexture(TX_BTN_PAUSE));
    sf::FloatRect buttonRect = buttonPauseContinue.getLocalBounds();
    buttonPauseContinue.setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
    buttonPauseContinue.setPosition(SCREEN_WIDTH - 75, 25);
    sf::IntRect bound(0, 0, 50, 50);
    buttonPauseContinue.setTextureRect(bound);

    buttonSave.setSize(sf::Vector2f (50, 50));
    buttonSave.setTexture(&textureManager.getTexture(TX_BTN_SAVE));
    buttonRect = buttonSave.getLocalBounds();
    buttonSave.setOrigin(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0);
    buttonSave.setPosition(SCREEN_WIDTH - 25, 25);
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
