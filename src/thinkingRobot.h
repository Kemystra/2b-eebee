#include <vector>

#include "robot.h"

using namespace std;


#ifndef THINKING_ROBOT_H
#define THINKING_ROBOT_H

class ThinkingRobot : public Robot {
protected:
    vector<Position> seenRobotPosition;

public:
    virtual void think(vector<Position> newRobotLocations) = 0;
};

#endif  // THINKING_ROBOT_H
