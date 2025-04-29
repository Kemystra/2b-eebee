#ifndef SEEING_ROBOT_H
#define SEEING_ROBOT_H

#include <vector>

#include "robot.h"
#include "../vector2d.h"

using namespace std;


class SeeingRobot : public Robot {
public:
    virtual vector<Vector2D> look(int x, int y) = 0;
};

#endif  // SEEING_ROBOT_H
