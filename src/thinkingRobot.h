#include <vector>

#include "robot.h"

using namespace std;


#ifndef THINKING_ROBOT_H
#define THINKING_ROBOT_H

class ThinkingRobot : public Robot {
    vector<Position> seenRobotPosition;

public:
    void think(vector<Position> newRobotLocations);
};

#endif  // THINKING_ROBOT_H
