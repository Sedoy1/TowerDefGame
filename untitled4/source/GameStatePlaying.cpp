#include "../headers/GameStatePlaying.h"
#include <memory>

void GameStatePlaying::StateRealization() {
    LogicEvent.MoveObject();
    if(LogicEvent.IsPlayerAlive()) {
        spawnerManager.UpdateWaves();
        RenderMnr.Draw(Enemies, player, gameField, buttonPauseContinue, buttonSave);

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
                    if (buttonPauseContinue.getGlobalBounds().contains(xPosition, yPosition)) {
                        Pause();
                    }
                }
                break;
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
RenderMnr(window, newTextureManager), spawnerManager(newTextureManager), textureManager(newTextureManager){
    LoadField();
    InitPlayer();
    InitButtons();
    LogicEvent.SetPlayableRules(enemyPath, &Enemies, player);
    spawnerManager.InitSpawnerOption(&Enemies, &enemyPath.begin()->second);
}

GameStatePlaying::~GameStatePlaying() {
    std::cout<<"Destructor Game state Playing"<<std::endl;
    // clear mem from enemies
    std::cout<<"end"<<std::endl;
}

void GameStatePlaying::InitPlayer() {
    player = std::make_shared<Player>(RenderMnr.TextureMnr.getTexture(TX_PLAYER), enemyPath.rbegin()->second);
}


void GameStatePlaying::RenderManagerPlay::DrawField(GameField &newGameField) {
    for(GameField::Iterator iterator = newGameField.Begin(); iterator != newGameField.End(); iterator ++){
        iterator.GetTile().sprite.Update();
        WindowLink.draw(iterator.GetTile().sprite);
    }
}


void GameStatePlaying::LoadField() {
    gameField.InitField();
    for(GameField::Iterator iterator = gameField.Begin(); iterator != gameField.End(); iterator ++){
        int id = iterator.GetTile().tileType;
        sf::Texture & texture = textureManager.getTexture(TexturesID(id));
        iterator.GetTile().sprite.setTexture(texture);
        iterator.GetTile().sprite.setPosition(iterator.coordinates.x * RenderManagerPlay::TILE_WIDTH,
                                              iterator.coordinates.y * RenderManagerPlay::TILE_HEIGHT);
    }
    enemyPath = *gameField.ComputeEnemiesPath();
}


void GameStatePlaying::RenderManagerPlay::Draw(std::vector<std::shared_ptr<Enemy>> &enemyVector, const std::shared_ptr<Player> &player,
                                               GameField &gameField,
                                               sf::RectangleShape &buttonPause, sf::RectangleShape &buttonSave) {
    DrawField(gameField);
    DrawEnemies(enemyVector);
    DrawPlayer(player);
    DrawButtons(buttonPause, buttonSave);
}


void GameStatePlaying::RenderManagerPlay::DrawEnemies(std::vector<std::shared_ptr<Enemy>> &enemyVector) {
    for(auto object: enemyVector){
        object->GetSprite().Update();
        WindowLink.draw(object->GetSprite());
    }
}

unsigned int GameStatePlaying::RenderManagerPlay::TILE_WIDTH = 50;
unsigned int GameStatePlaying::RenderManagerPlay::TILE_HEIGHT = 50;

void GameStatePlaying::RenderManagerPlay::LoadObjectsTexture() {
    TextureMnr.LoadTexture(TX_BLACK_GHOST, BLACK_GHOST_TEXTURE);
    TextureMnr.LoadTexture(TX_WHITE_GHOST, WHITE_GHOST_TEXTURE);
    TextureMnr.LoadTexture(TX_PLAYER, PLAYER_TEXTURE);
}

GameStatePlaying::RenderManagerPlay::~RenderManagerPlay() {
    std::cout<<"Destructor renderManager Play\n";
    std::cout<<"end renderManager play\n";
}

void GameStatePlaying::RenderManagerPlay::DrawPlayer(const std::shared_ptr<Player> &player) {
    player->GetSprite().Update();
    WindowLink.draw(player->GetSprite());
}

void GameStatePlaying::RenderManagerPlay::LoadFieldTexture() {
    TextureMnr.LoadTexture(TX_GRASS, GRASS_TEXTURE);
    TextureMnr.LoadTexture(TX_START, START_TEXTURE);
    TextureMnr.LoadTexture(TX_PLAIN, PLAIN_TEXTURE);
    TextureMnr.LoadTexture(TX_TRAIL, TRAIL_TEXTURE);
    TextureMnr.LoadTexture(TX_FINISH, FINISH_TEXTURE);
}

void GameStatePlaying::RenderManagerPlay::LoadButtonsTexture() {
    TextureMnr.LoadTexture(TX_BTN_PAUSE, BUTTON_PAUSE_CONTINUE);
    TextureMnr.LoadTexture(TX_BTN_SAVE, BUTTON_SAVE);
}

GameStatePlaying::RenderManagerPlay::RenderManagerPlay(sf::RenderWindow &window, TextureManager &textureManager)
        : RenderManager(window, textureManager) {
    LoadFieldTexture();
    LoadObjectsTexture();
    LoadButtonsTexture();
}

void GameStatePlaying::RenderManagerPlay::DrawButtons(sf::RectangleShape &newButtonPause,
                                                      sf::RectangleShape &newButtonSave) {
    WindowLink.draw(newButtonPause);
    WindowLink.draw(newButtonSave);
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
    RenderMnr.Draw(Enemies, player, gameField, buttonPauseContinue, buttonSave);
    Game_->Window.display();
    auto bgTexture = new sf::Texture;
    bgTexture->create(SCREEN_WIDTH, SCREEN_HEIGHT);
    bgTexture->update(Game_->Window);
    Game_->pushState(new GameStatePause(Game_, Game_->Window, Game_->TextureMnr, bgTexture));
    bound.left -= 50;
    buttonPauseContinue.setTextureRect(bound);
}
