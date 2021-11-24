#ifndef UNTITLED4_BLINKINGTEXT_H
#define UNTITLED4_BLINKINGTEXT_H
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "ElementsDefinition.h"

class BlinkingText:public sf::Text{
private:
    sf::Font font;
    Animation animation;
    bool blink = false;
public:
    void Update();
    void InitText(std::string &newText, sf::Color newColor=sf::Color::Black, sf::Text::Style typeText=sf::Text::Bold, int newCharSize=32);
    bool GetBlinkState();
};

#endif //UNTITLED4_BLINKINGTEXT_H
