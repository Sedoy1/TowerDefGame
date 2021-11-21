#include "../headers/GameStatePlaying.h"
#include <memory>

void GameStatePlaying::StateRealization() {
    LogicEvent.MoveObject();
    if(LogicEvent.IsPlayerAlive()) {
        spawnerManager.UpdateWaves();
        RenderMnr.Draw(Enemies, player, gameField);

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
            default: break;
        }
    }
}

void GameStatePlaying::Update() {
    Game_->Window.display();
    Game_->Window.clear();
}

GameStatePlaying::GameStatePlaying(Game *game, sf::RenderWindow &window, TextureManager &newTextureManager): GameState(game),
textureManager(newTextureManager), RenderMnr(window, newTextureManager), spawnerManager(newTextureManager){
    LoadField();
    InitPlayer();
    LogicEvent.SetPlayableRules(&enemyPath, &Enemies, player);
    spawnerManager.InitSpawnerOption(&Enemies, &enemyPath.begin()->second);
}

GameStatePlaying::~GameStatePlaying() {
    std::cout<<"Destructor Game state Playing"<<std::endl;
    // clear mem from enemies
    for(auto enemy: Enemies){
        delete enemy;
    }
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


void GameStatePlaying::RenderManagerPlay::Draw(std::vector<Enemy *> &enemyVector, const std::shared_ptr<Player> &player,
                                               GameField &gameField) {
    DrawField(gameField);
    DrawEnemies(enemyVector);
    DrawPlayer(player);
}


void GameStatePlaying::RenderManagerPlay::DrawEnemies(std::vector<Enemy *> &enemyVector) {
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
    std::cout<<"Destructor Manager Play\n";
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

void GameStatePlaying::GameOver() {
    Game_->changeState(new GameStateGameEnd(Game_, Game_->Window, Game_->TextureMnr, LOOSE));
}

void GameStatePlaying::Win() {
    Game_->changeState(new GameStateGameEnd(Game_, Game_->Window, Game_->TextureMnr, WIN));
}
