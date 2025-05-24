#ifndef MOVING_ROBOT_H
#define MOVING_ROBOT_H

#include "robot.h"
#include "../vector2d.h"


class MovingRobot : public Robot {
    virtual void move(int x, int y) = 0;
};

#endif  // MOVING_ROBOT_H
