#include "../headers/BlinkingText.h"

void BlinkingText::Update() {
    if(animation.timeStart > animation.duration){
        blink = !blink;
        animation.timeStart = 0.0f;
    }
    else{
        animation.timeStart += animation.timeStep;
    }
}

bool BlinkingText::GetBlinkState() {
    return blink;
}

void BlinkingText::InitText(std::string &newText, sf::Color newColor, sf::Text::Style typeText, int newCharSize) {
    font.loadFromFile(TEXT_FONT);
    Animation newAnimation(20.0f);
    animation = newAnimation;
    this->setString(newText);
    this->setFont(font);
    this->setCharacterSize(newCharSize);
    this->setFillColor(newColor);
    this->setStyle(typeText);
}
