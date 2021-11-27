#ifndef UNTITLED4_INPUTCONTROLLER_H
#define UNTITLED4_INPUTCONTROLLER_H

#include "SFML/Graphics.hpp"

enum HandleAnswer{
    NONE,
    CLOSE_CLICK,
    LEFT_BUTTON_MOUSE_CLICK,
    ESCAPE_PRESSED,
    L_PRESSED
};

class InputController {
    static int CheckInput(sf::Event & event, int & xPosition, int & yPosition){
        switch(event.type)
        {
            case sf::Event::Closed:
            {
                return CLOSE_CLICK;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    return ESCAPE_PRESSED;
                else if(event.key.code == sf::Keyboard::L){
                    return L_PRESSED;
                }
            }
            case sf::Event::MouseButtonPressed:
            {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    xPosition = event.mouseButton.x;
                    yPosition = event.mouseButton.y;
                    return LEFT_BUTTON_MOUSE_CLICK;
                }
            }
            default: return NONE;
        }
    }
};


#endif //UNTITLED4_INPUTCONTROLLER_H
