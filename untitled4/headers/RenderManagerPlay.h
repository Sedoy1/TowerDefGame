#ifndef UNTITLED4_RENDERMANAGERPLAY_H
#define UNTITLED4_RENDERMANAGERPLAY_H
#include "ElementsDefinition.h"
#include <cassert>
#include "GameField.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "AnimationSprite.h"
#include "SFML/Graphics.hpp"
#include "RenderManager.h"
#include "Enemy.h"
#include "Player.h"
class TextureManager;

class RenderManagerPlay: public RenderManager{
    private:
    GameField gameField;
    void DrawField();
    void DrawEnemies(std::vector<Enemy *> &enemyVector);
    void LoadField();
    void LoadEnemies();
    public:
    RenderManagerPlay(sf::RenderWindow &window, TextureManager & textureManager):RenderManager(window, textureManager){LoadField(); LoadEnemies();}
    ~RenderManagerPlay();
    std::map<int, Coordinate> * EnemyPath();
    void Draw(std::vector<Enemy *> &enemyVector, const std::shared_ptr<Player> &player);
    static unsigned int TILE_HEIGHT;
    static unsigned int TILE_WIDTH;

    void DrawPlayer(const std::shared_ptr<Player> &player);
};


#endif //UNTITLED4_RENDERMANAGERPLAY_H
