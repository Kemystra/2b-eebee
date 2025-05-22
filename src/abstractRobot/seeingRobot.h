#ifndef SEEING_ROBOT_H
#define SEEING_ROBOT_H

#include <vector>

#include "robot.h"
#include "../vector2d.h"

using namespace std;


class SeeingRobot : public Robot {
protected:
    vector<Vector2D> seenRobotPosition = {};
public:
    virtual vector<Vector2D> look(Vector2D center) = 0;
};

#endif  // SEEING_ROBOT_H
