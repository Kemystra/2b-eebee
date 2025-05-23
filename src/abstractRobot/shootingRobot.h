#ifndef SHOOTING_ROBOT_H
#define SHOOTING_ROBOT_H

#include "robot.h"
#include "../vector2d.h"


class ShootingRobot : public Robot {
protected:
    int shellCount = 10;
    // Fire a shot at a position
    // Shot position is calculated offset from robot's position
public:
    virtual void fire(int x, int y) = 0;

    // Needed for upgrades
    virtual int getMaxFiringDistance() const = 0;
    virtual int getBulletsPerShot() const = 0;
};

#endif // SHOOTING_ROBOT_H
