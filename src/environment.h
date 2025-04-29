#include <vector>

#include "abstractRobot/robot.h"
#include "vector2d.h"

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
    bool isRobotHere(Vector2D position);
    bool isPositionAvailable(Vector2D position);
};

#endif  // ENVIRONMENT_H
