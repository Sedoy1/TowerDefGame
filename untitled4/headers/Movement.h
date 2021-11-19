#ifndef UNTITLED4_MOVEMENT_H
#define UNTITLED4_MOVEMENT_H
#include "Coordinate.h"

class Movement{
private :
    sf::Vector2f duration;
    sf::Vector2f speed;
    void ComputeDuration(int speedX, int speedY){
        speedX == 0 ? duration.x = 0 : duration.x = 50.0f / speedX;;
        speedY == 0 ? duration.y = 0 : duration.y = 50.0f / speedY;
    }
public:
    bool isArrived;
    float timeStart;
    float timeStep; // speed in time = 1 loop pass
    float GetDuration() const{
        return std::max(duration.x, duration.y);
    }
    void SetSpeed(int speedX, int speedY){
        speed = sf::Vector2f (speedX, speedY);
        ComputeDuration(abs(speedX), abs(speedY));
    }
    sf::Vector2f GetSpeed() const{
        return speed;
    }
    Movement(){
        isArrived = true;
        timeStep = 0.f;
        timeStart = 0.f;
    }
    Movement(int){
        isArrived = false;
        timeStep = 1.0f;
        timeStart = 0.f;
    }

};

#endif //UNTITLED4_MOVEMENT_H
