#ifndef SHOOTING_ROBOT_H
#define SHOOTING_ROBOT_H

#include "robot.h"
#include "../vector2d.h"


class ShootingRobot : public Robot {
private:
    int shellCount = 10;
    // Fire a shot at a position
    // Shot position is calculated offset from robot's position
public:
    virtual void fire(Vector2D target) = 0;
};

#endif // SHOOTING_ROBOT_H
