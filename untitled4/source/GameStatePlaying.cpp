#include "../headers/GameStatePlaying.h"

#include <memory>

void GameStatePlaying::StateRealization() {
    LogicEvent.MoveObject();
    if(LogicEvent.IsPlayerAlive())
    RenderMnr.Draw(Enemies, player);
    else{
        //TODO поменять состояние на геймовер
        std::cout<<"GameOver\n"<<std::endl;
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

GameStatePlaying::GameStatePlaying(Game *game, sf::RenderWindow &window, TextureManager &textureManager): GameState(game),
RenderMnr(window, textureManager), LogicEvent(){
    InitPlayer();
    InitLevelComplexity();
    LogicEvent.SetPlayableRules(RenderMnr.EnemyPath(), &Enemies, player);

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

void GameStatePlaying::SpawnEnemies() {

}

void GameStatePlaying::InitLevelComplexity() {
    EnemiesNumber[ENEMY_BLACK_GHOST] = 5;
    EnemiesNumber[ENEMY_WHITE_GHOST] = 2;
}

