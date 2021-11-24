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
    TX_BG_BUTTONS,
    TX_BTN_WEAPON_BLUE,
    TX_BTN_WEAPON_ORANGE,
    TX_BTN_WEAPON_BLACK,
    TX_BLACK_GHOST,
    TX_WHITE_GHOST,
    TX_RED_GHOST, //TODO добавить еще 2 вида врагов
    TX_BROWN_GHOST,
    TX_BLUE_CANNON,
    TX_ORANGE_CANNON,
    TX_BLACK_CANNON,
    TX_HEALTH
};

class TextureManager{
    private: // можно оптимизировать, проверяя используется ли текстура в данный момент игры или нет и подгружать ее
        std::map<int , sf::Texture> Textures;
    public:
        void LoadTexture(int Id, const std::string & Path);
        sf::Texture & getTexture(int Id);
};

#endif //UNTITLED4_TEXTUREMANAGER_H
