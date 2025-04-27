#include "robot.h"

#ifndef SHOOTING_ROBOT_H
#define SHOOTING_ROBOT_H

class ShootingRobot : public Robot {

    // Fire a shot at a position
    // Shot position is calculated offset from robot's position
    virtual void fire(int x, int y) = 0;
};

#endif // SHOOTING_ROBOT_H
