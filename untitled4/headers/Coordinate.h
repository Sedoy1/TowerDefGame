#ifndef UNTITLED4_COORDINATE_H
#define UNTITLED4_COORDINATE_H
#include <SFML/Graphics.hpp>

struct Coordinate: public sf::Vector2i {
    Coordinate(){
        x=0;
        y=0;
    }
    Coordinate(int x_, int y_):sf::Vector2i(x_, y_){}
};

#endif //UNTITLED4_COORDINATE_H
