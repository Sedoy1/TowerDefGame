#ifndef UNTITLED4_INPUTCONTROLLER_H
#define UNTITLED4_INPUTCONTROLLER_H
#include "SFML/Graphics.hpp"

enum HandleAnswer{
    NONE_INPUT,
    CLOSE_CLICK,
    LEFT_BUTTON_MOUSE_CLICK,
    ESCAPE_PRESSED,
    L_PRESSED,
    LOAD_SAVE_PRESSED,
    MOUSE_MOVED
};

class InputControllerTest {
private:
    sf::Keyboard::Key  exitButton;
    sf::Keyboard::Key loggerButton;
    sf::Keyboard::Key loadSavedGame;
    sf::Mouse::Button clickMouseButton;
public:

    void InitButtons(sf::Keyboard::Key newButtonExit, sf::Keyboard::Key newButtonLogger,
                     sf::Mouse::Button newClickMouseButton,
                     sf::Keyboard::Key keyLoadSave) {
        exitButton = newButtonExit;
        loggerButton = newButtonLogger;
        clickMouseButton = newClickMouseButton;
        loadSavedGame = keyLoadSave;
    }

    int CheckInput(sf::Event & event) const {
        if ((event.key.code == exitButton and event.type== sf::Event::KeyPressed) or event.type == sf::Event::Closed)
            return CLOSE_CLICK;
        else if (event.key.code == loggerButton and event.type== sf::Event::KeyPressed) {
            return L_PRESSED;
        } else if (event.mouseButton.button == clickMouseButton and event.type== sf::Event::MouseButtonPressed) {
            return LEFT_BUTTON_MOUSE_CLICK;
        } else if (event.type == sf::Event::MouseMoved) {
            return MOUSE_MOVED;
        } else if (event.key.code == loadSavedGame and event.type== sf::Event::KeyPressed)
            return LOAD_SAVE_PRESSED;
        return NONE_INPUT;
    }
};

#endif //UNTITLED4_INPUTCONTROLLER_H
