#ifndef UNTITLED4_ANIMATION_H
#define UNTITLED4_ANIMATION_H
#include "random"

struct Animation{
    unsigned int startFrame=0;
    unsigned int endFrame=0;
    unsigned int currentAnim;
    float duration=0.f;
    unsigned int GetLen() const;
    float timeStart=0.f;
    float timeStep=0.f;
    Animation(unsigned int new_startFrame, unsigned int new_endFrame, float new_duration, float new_timeStep);
    Animation(Animation & other);
    //default constructor for arr
    Animation();
};

#endif //UNTITLED4_ANIMATION_H
