#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <string>

#include "vector2d.h"

using namespace std;


// Forward declaration to avoid recursive includes
// Basically Environment depends on GenericRobot, but GenericRobot ALSO depends on Environment
// Compiler complains about this
// Instead of including, we just write the declaration directly
class GenericRobot;

struct RobotParameter {
    string name;
    Vector2D position;
};


// Class to store everything related to the overall environment stuff
// Implement environment checking here
class Environment {
private:
    vector<GenericRobot> robotList;

    // Width and height of the battleground
    Vector2D dimension;

    int maxStep;
    int step;

public:
    Environment(int maxStep, Vector2D dimension, vector<RobotParameter> robotParams);
    bool isRobotHere(Vector2D positionToCheck) const;
    bool isPositionAvailable(Vector2D positionToCheck) const;
};

#endif  // ENVIRONMENT_H
