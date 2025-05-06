#include "environment.h"
#include "genericRobot.h"

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
