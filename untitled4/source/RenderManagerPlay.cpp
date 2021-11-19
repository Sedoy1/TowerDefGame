#include "../headers/RenderManagerPlay.h"

void RenderManagerPlay::DrawField() {
    for(GameField::Iterator iterator = gameField.Begin(); iterator != gameField.End(); iterator ++){
        iterator.GetTile().sprite.Update();
        WindowLink.draw(iterator.GetTile().sprite);
    }
}


void RenderManagerPlay::LoadField() {
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


void RenderManagerPlay::Draw(std::vector<Enemy *> &enemyVector, const std::shared_ptr<Player> &player) {
    DrawField();
    DrawEnemies(enemyVector);
    DrawPlayer(player);
}


void RenderManagerPlay::DrawEnemies(std::vector<Enemy *> &enemyVector) {
    for(auto object: enemyVector){
        object->GetSprite().Update();
        WindowLink.draw(object->GetSprite());
    }
}

unsigned int RenderManagerPlay::TILE_WIDTH = 50;
unsigned int RenderManagerPlay::TILE_HEIGHT = 50;

void RenderManagerPlay::LoadEnemies() {
    TextureMnr.LoadTexture(TX_EN_GHOST, ENEMY_GHOST_TEXTURE);
    TextureMnr.LoadTexture(TX_PLAYER, PLAYER_TEXTURE);
}

std::map<int, Coordinate> *RenderManagerPlay::EnemyPath() {
    return gameField.ComputeEnemiesPath();
}

RenderManagerPlay::~RenderManagerPlay() {
    std::cout<<"Destructor Manager Play\n";
}

void RenderManagerPlay::DrawPlayer(const std::shared_ptr<Player> &player) {
    player->GetSprite().Update();
    WindowLink.draw(player->GetSprite());
}
