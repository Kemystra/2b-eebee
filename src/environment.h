#include <vector>

#include "abstractRobot/robot.h"

using namespace std;


#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

// Class to store everything related to the overall environment stuff
// Implement environment checking here
class Environment {
private:
    vector<Robot> robotList;
    int height;
    int width;

public:
    bool isRobotHere(int x, int y);
    bool isPositionAvailable(int x, int y);
};

#endif  // ENVIRONMENT_H
