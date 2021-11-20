#ifndef UNTITLED4_RENDERMANAGER_H
#define UNTITLED4_RENDERMANAGER_H
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "ElementsDefinition.h"

class RenderManager{
public:
    sf::RenderWindow & WindowLink;
    TextureManager & TextureMnr;
    RenderManager(sf::RenderWindow &window, TextureManager & textureManager):WindowLink(window), TextureMnr(textureManager){
        font.loadFromFile(TEXT_FONT);
    }

protected:
    sf::Font font;
};



#endif //UNTITLED4_RENDERMANAGER_H
