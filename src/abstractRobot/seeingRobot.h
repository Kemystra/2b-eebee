#ifndef SEEING_ROBOT_H
#define SEEING_ROBOT_H

#include <vector>

#include "robot.h"
#include "../vector2d.h"

using namespace std;


class SeeingRobot : public Robot {
public:
    virtual void look(Vector2D center) = 0;
};

#endif  // SEEING_ROBOT_H
