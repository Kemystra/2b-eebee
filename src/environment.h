#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <string>

#include "genericRobot.h"
#include "vector2d.h"

using namespace std;


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
    bool isRobotHere(Vector2D position);
    bool isPositionAvailable(Vector2D position);
};

#endif  // ENVIRONMENT_H
