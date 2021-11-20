#include "../headers/GameStatePlaying.h"

#include <memory>

void GameStatePlaying::StateRealization() {
    LogicEvent.MoveObject();
    if(LogicEvent.IsPlayerAlive()) {
        spawnerManager.UpdateWaves();
        RenderMnr.Draw(Enemies, player);

        if(spawnerManager.GetWaveState()){
            //TODO поменять состояние на победу
            std::cout<<"Win\n"<<std::endl;
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
    InitPlayer();
    //TODO enemyPath нужно вытащить и высчитыват где то НЕ В РЕНДЕРЕ БЛЯТЬ ЧТО ПРОИСХОДИИИИТ
    LogicEvent.SetPlayableRules(RenderMnr.EnemyPath(), &Enemies, player);
    spawnerManager.InitSpawnerOption(&Enemies, &RenderMnr.EnemyPath()->begin()->second);
}

GameStatePlaying::~GameStatePlaying() {
    std::cout<<"Destructor Game state Playing"<<std::endl;
    // clear mem from enemies
    for(auto enemy: Enemies){
        delete enemy;
    }
}

void GameStatePlaying::InitPlayer() {
    Animation playerAnimation (0, 2, 1.0f, 0.2f);
    player = std::make_shared<Player>(RenderMnr.TextureMnr.getTexture(TX_PLAYER), playerAnimation, RenderMnr.EnemyPath()->rbegin()->second);
}


void GameStatePlaying::RenderManagerPlay::DrawField() {
    for(GameField::Iterator iterator = gameField.Begin(); iterator != gameField.End(); iterator ++){
        iterator.GetTile().sprite.Update();
        WindowLink.draw(iterator.GetTile().sprite);
    }
}


void GameStatePlaying::RenderManagerPlay::LoadField() {
    TextureMnr.LoadTexture(TX_GRASS, GRASS_TEXTURE);
    TextureMnr.LoadTexture(TX_START, START_TEXTURE);
    TextureMnr.LoadTexture(TX_PLAIN, PLAIN_TEXTURE);
    TextureMnr.LoadTexture(TX_TRAIL, TRAIL_TEXTURE);
    TextureMnr.LoadTexture(TX_FINISH, FINISH_TEXTURE);

    gameField.InitField();

    for(GameField::Iterator iterator = gameField.Begin(); iterator != gameField.End(); iterator ++){
        int id = iterator.GetTile().tileType;
        sf::Texture & texture = TextureMnr.getTexture(TexturesID(id));
        iterator.GetTile().sprite.setTexture(texture);
        iterator.GetTile().sprite.setPosition(iterator.coordinates.x * RenderManagerPlay::TILE_WIDTH,
                                              iterator.coordinates.y * RenderManagerPlay::TILE_HEIGHT);
    }
}


void GameStatePlaying::RenderManagerPlay::Draw(std::vector<Enemy *> &enemyVector, const std::shared_ptr<Player> &player) {
    DrawField();
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

void GameStatePlaying::RenderManagerPlay::LoadEnemies() {
    TextureMnr.LoadTexture(TX_BLACK_GHOST, BLACK_GHOST_TEXTURE);
    TextureMnr.LoadTexture(TX_PLAYER, PLAYER_TEXTURE);
    TextureMnr.LoadTexture(TX_WHITE_GHOST, WHITE_GHOST_TEXTURE);
}

std::map<int, Coordinate> *GameStatePlaying::RenderManagerPlay::EnemyPath() {
    return gameField.ComputeEnemiesPath();
}

GameStatePlaying::RenderManagerPlay::~RenderManagerPlay() {
    std::cout<<"Destructor Manager Play\n";
}

void GameStatePlaying::RenderManagerPlay::DrawPlayer(const std::shared_ptr<Player> &player) {
    player->GetSprite().Update();
    WindowLink.draw(player->GetSprite());
}

void GameStatePlaying::GameOver() {
    Game_->changeState(new GameStateGameOver(Game_, Game_->Window, Game_->TextureMnr));
}
