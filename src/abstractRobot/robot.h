#ifndef ROBOT_H 
#define ROBOT_H

#include "../vector2d.h"

class Robot {
public:
    virtual void gotHit() = 0;
    virtual void die() = 0;
    virtual void executeTurn() = 0;
};

#endif // !ROBOT_H
