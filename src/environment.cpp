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
        if (robot.getPosition() == positionToCheck)
            return true;
    }

    return false;
}

bool Environment::isPositionAvailable(Vector2D positionToCheck) const {
    // only 1 robot at 1 position
    if (isRobotHere(positionToCheck))
        return false;

    // Cannot go out of bounds of the battleground
    if(positionToCheck.x > dimension.x || positionToCheck.x < 0)
        return false;

    if(positionToCheck.y > dimension.y || positionToCheck.y < 0)
        return false;

    return true;
}

void Environment::printMap() const {
    // Print column headers (X axis)
    cout << "   ";
    for (int x = 0; x < dimension.x; ++x) {
        cout << x << " ";
    }
    cout << "\n";
    for (int y = 0; y < dimension.y; ++y) {
        // Print row header (Y axis)
        cout << y << " |";
        for (int x = 0; x < dimension.x; ++x) {
            Vector2D pos(x, y);
            bool found = false;
            for (const GenericRobot &robot : robotList) {
                if (robot.getPosition() == pos) {
                    cout << robot.getSymbol() << " ";
                    found = true;
                    break;
                }
            }
            if (!found) cout << ". ";
        }
        cout << "|\n";
    }
    // Print cardinal directions
    cout << "\nN (up)\nS (down)\nE (right)\nW (left)\n";
}
