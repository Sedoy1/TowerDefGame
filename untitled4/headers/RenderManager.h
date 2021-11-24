#ifndef UNTITLED4_RENDERMANAGER_H
#define UNTITLED4_RENDERMANAGER_H
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "ElementsDefinition.h"

class RenderManager{
public:
    sf::RenderWindow & WindowLink;
    RenderManager(sf::RenderWindow &window, TextureManager & textureManager): WindowLink(window), textureManager(textureManager){
        font.loadFromFile(TEXT_FONT);
    }
    sf::Texture & GetTexture(int ID){
        return textureManager.getTexture(ID);
    }
protected:
    sf::Font font;
    TextureManager & textureManager;
};



#endif //UNTITLED4_RENDERMANAGER_H
