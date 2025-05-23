#ifndef ROBOT_H 
#define ROBOT_H

#include <vector>
#include <string.h>

#include "../vector2d.h"

using namespace std;


// More forward declaration
class Environment;

enum DeadState {
    Respawn, Dead
};

enum RobotUpgrades {
};


class Robot {
public:
    virtual void gotHit() = 0;
    virtual DeadState die() = 0;

    virtual vector<RobotUpgrades> getUpgrades() const = 0;
    virtual string getName() const = 0;
    virtual Vector2D getPosition() const = 0;
};

#endif // !ROBOT_H
