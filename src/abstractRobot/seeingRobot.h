#include <vector>
#include "robot.h"

using namespace std;


#ifndef SEEING_ROBOT_H
#define SEEING_ROBOT_H

class SeeingRobot : public Robot {
public:
    virtual vector<Position> look(int x, int y) = 0;
};

#endif  // SEEING_ROBOT_H
