#ifndef UNTITLED4_INPUTCONTROLLER_H
#define UNTITLED4_INPUTCONTROLLER_H
#include "SFML/Graphics.hpp"

enum HandleAnswer{
    NONE_INPUT,
    CLOSE_CLICK,
    LEFT_BUTTON_MOUSE_CLICK,
    ESCAPE_PRESSED,
    L_PRESSED,
    MOUSE_MOVED
};

class InputController {
public:
    static int CheckInput(sf::Event & event){
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
                    return LEFT_BUTTON_MOUSE_CLICK;
                }
            }
            case sf::Event::MouseMoved:
                return MOUSE_MOVED;
            default: return NONE_INPUT;
        }
    }
};


#endif //UNTITLED4_INPUTCONTROLLER_H
