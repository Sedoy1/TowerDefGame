#ifndef UNTITLED4_RENDERMANAGERMENU_H
#define UNTITLED4_RENDERMANAGERMENU_H
#include "RenderManager.h"


class RenderManagerMenu: public RenderManager{
    public:
    RenderManagerMenu(sf::RenderWindow & window, TextureManager & textureManager): RenderManager(window, textureManager){}
    void Draw();

private:
    sf::Sprite MenuBg;
    void DrawMenu();
    void DrawBg();
};


#endif //UNTITLED4_RENDERMANAGERMENU_H
