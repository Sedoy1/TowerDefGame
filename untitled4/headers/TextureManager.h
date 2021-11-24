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
    TX_BTN_START,
    TX_BTN_OPTIONS,
    TX_BTN_LOAD_GAME,
    TX_BTN_EXIT,
    TX_BTN_CONTINUE,
    TX_BTN_PAUSE,
    TX_BTN_SAVE,
    TX_BTN_MENU,
    TX_BTN_RESTART,
    TX_PLAYER,
    TX_BLACK_GHOST,
    TX_WHITE_GHOST,
    TX_RED_GHOST, //TODO добавить еще 2 вида врагов
    TX_BLUE_GHOST,
    TX_CANNON
};

class TextureManager{
    private: // можно оптимизировать, проверяя используется ли текстура в данный момент игры или нет и подгружать ее
        std::map<int , sf::Texture> Textures;
    public:
        void LoadTexture(int Id, const std::string & Path);
        sf::Texture & getTexture(int Id);
};

#endif //UNTITLED4_TEXTUREMANAGER_H
