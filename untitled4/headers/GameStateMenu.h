#ifndef UNTITLED4_GAMESTATEMENU_H
#define UNTITLED4_GAMESTATEMENU_H
#include "GameState.h"
#include "GameStatePlaying.h"

class GameStateMenu : public GameState{
public:
    void StateRealization() override;
    void HandleInput() override;
    void Update() override;
    GameStateMenu(Game * game, sf::RenderWindow &window, TextureManager & textureManager): GameState(game), RenderMnr(window, textureManager) {}
    ~GameStateMenu();
private:
    void LoadGame();
    class RenderManagerMenu: public RenderManager{
    public:
        RenderManagerMenu(sf::RenderWindow & window, TextureManager & textureManager): RenderManager(window, textureManager){}
        void Draw();

    private:
        sf::Sprite MenuBg;
        void DrawMenu();
        void DrawBg();
    };
    RenderManagerMenu RenderMnr;
};


#endif //UNTITLED4_GAMESTATEMENU_H
