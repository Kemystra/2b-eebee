#include "environment.h"
#include "genericRobot.h"
#include "vector2d.h"

using namespace std;

Environment::Environment(
    int maxStep,
    Vector2D dimension,
    vector<RobotParameter> robotParams
) {
    this->maxStep = maxStep;
    this->dimension = dimension;

    for (const RobotParameter &param : robotParams) {
        GenericRobot robot(param.position, param.name);
        this->robotList.push_back(robot);
    }
}

bool Environment::isRobotHere(Vector2D positionToCheck) const {
    for (const GenericRobot &robot : this->robotList) {
        if (robot.position == positionToCheck)
            return true;
    }

    return false;
}
