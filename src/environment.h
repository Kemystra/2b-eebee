#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>

#include "abstractRobot/robot.h"
#include "vector2d.h"

using namespace std;


// Class to store everything related to the overall environment stuff
// Implement environment checking here
class Environment {
private:
    vector<Robot> robotList;

    // Width and height of the battleground
    Vector2D dimension;

public:
    bool isRobotHere(Vector2D position);
    bool isPositionAvailable(Vector2D position);
};

#endif  // ENVIRONMENT_H
