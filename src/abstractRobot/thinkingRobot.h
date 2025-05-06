#ifndef THINKING_ROBOT_H
#define THINKING_ROBOT_H

#include <vector>
#include "../vector2d.h"

#include "robot.h"

using namespace std;


class ThinkingRobot : public Robot {
public:
    virtual void think() = 0;
};

#endif  // THINKING_ROBOT_H
