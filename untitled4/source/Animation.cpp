#include "../headers/Animation.h"

Animation::Animation(unsigned int new_startFrame, unsigned int new_endFrame, float new_duration,
                                      float new_timeStep) {
    startFrame = new_startFrame;
    endFrame = new_endFrame;
    duration = new_duration;
    timeStep = new_timeStep;
    timeStart = duration;
    currentAnim = rand()%GetLen();
}

unsigned int Animation::GetLen() const {
    return (endFrame - startFrame) + 1;
}



// constructor for array or object without animation
Animation::Animation() {
    startFrame = 0;
    endFrame = 1;
    duration = 0.0f;
    timeStep = 0.0f;
    timeStart = duration;
    currentAnim = 0;
}

Animation::Animation(float newDuration, float newTimeStep) {
    startFrame = 0;
    endFrame = 1;
    duration = newDuration;
    timeStep = newTimeStep;
    timeStart = 0.0f;
    currentAnim = 0;
}
