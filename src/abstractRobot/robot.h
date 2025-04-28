#include "../vector2d.h"


#ifndef ROBOT_H 
#define ROBOT_H

class Robot {
protected:
    Vector2D position;
public:
    virtual void gotHit() = 0;
    virtual void die() = 0;
    virtual void executeTurn() = 0;
};

#endif // !ROBOT_H
