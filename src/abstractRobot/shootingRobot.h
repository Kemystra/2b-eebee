#ifndef SHOOTING_ROBOT_H
#define SHOOTING_ROBOT_H

#include "robot.h"
#include "../vector2d.h"


class ShootingRobot : public Robot {

    // Fire a shot at a position
    // Shot position is calculated offset from robot's position
    virtual void fire(Vector2D target) = 0;
};

#endif // SHOOTING_ROBOT_H
