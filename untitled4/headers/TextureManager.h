#ifndef UNTITLED4_TEXTUREMANAGER_H
#define UNTITLED4_TEXTUREMANAGER_H
#include "SFML/Graphics.hpp"
#include "ElementsDefinition.h"

enum TexturesID{
    TX_GRASS,
    TX_TRAIL,
    TX_PLAIN,
    TX_START,
    TX_FINISH,
    TX_MENU_BG,
    TX_PLAYER,
    TX_BLACK_GHOST,
    TX_WHITE_GHOST
};

class TextureManager{
    private: // можно оптимизировать, проверяя используется ли текстура в данный момент игры или нет и подгружать ее
        std::map<int , sf::Texture> Textures;
    public:
        void LoadTexture(int Id, const std::string & Path);
        sf::Texture & getTexture(int Id);
};

#endif //UNTITLED4_TEXTUREMANAGER_H
