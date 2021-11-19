#include "../headers/RenderManagerMenu.h"

void RenderManagerMenu::Draw() {
    DrawBg();
}

void RenderManagerMenu::DrawBg() {
    MenuBg.setTexture(TextureMnr.getTexture(TX_MENU_BG));
    WindowLink.draw(MenuBg);
}

void RenderManagerMenu::DrawMenu() {
    //TODO прорисовать меню
}
