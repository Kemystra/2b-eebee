#include "environment.h"

using namespace std;

Environment::Environment(
    int maxStep,
    Vector2D dimension,
    vector<RobotParameter> robotParams
) {
    this->maxStep = maxStep;
    this->dimension = dimension;

    // Instantiate robots here
    // and put into robotList
}
