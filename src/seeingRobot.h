#include <vector>
#include "robot.h"

using namespace std;


#ifndef SEEING_ROBOT_H
#define SEEING_ROBOT_H

class SeeingRobot : public Robot {
public:
    vector<Position> look(int x, int y);
};

#endif  // SEEING_ROBOT_H
