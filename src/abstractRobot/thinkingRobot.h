#include <vector>
#include "../vector2d.h"

#include "robot.h"

using namespace std;


#ifndef THINKING_ROBOT_H
#define THINKING_ROBOT_H

class ThinkingRobot : public Robot {
public:
    virtual void think(vector<Vector2D> newRobotLocations) = 0;
};

#endif  // THINKING_ROBOT_H
