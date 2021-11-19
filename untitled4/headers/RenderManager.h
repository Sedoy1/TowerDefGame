#ifndef UNTITLED4_RENDERMANAGER_H
#define UNTITLED4_RENDERMANAGER_H
#include "SFML/Graphics.hpp"
#include "TextureManager.h"

class RenderManager{
public:
    sf::RenderWindow & WindowLink;
    TextureManager & TextureMnr;
    RenderManager(sf::RenderWindow &window, TextureManager & textureManager):WindowLink(window), TextureMnr(textureManager){}
};



#endif //UNTITLED4_RENDERMANAGER_H
