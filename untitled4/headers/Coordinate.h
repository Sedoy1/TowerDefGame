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

static bool CheckDigit(std::string & str){
    for(int i=0; i<str.size(); i++){
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

#endif //UNTITLED4_COORDINATE_H
