#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <string>

#include "logger.h"
#include "vector2d.h"
#include "genericRobot.h"

using namespace std;


// Class to store everything related to the overall environment stuff
// Implement environment checking here
class Environment {
private:
    vector<GenericRobot*> robotList;
    Logger* logger;

    // Width and height of the battleground
    Vector2D dimension;

    int maxStep;
    int step = 0;

    // Values in milliseconds
    int robotActionInterval = 100;
    int stepInterval = 200;

public:
    Environment(
        int maxStep,
        Vector2D dimension,
        vector<RobotParameter> robotParams,
        Logger* logger
    );

    bool isRobotHere(Vector2D positionToCheck) const;
    GenericRobot* getRobotAtPosition(Vector2D positionToCheck);
    bool isPositionAvailable(Vector2D positionToCheck) const;
    // Print the map grid with robot positions and cardinal directions
    void printMap() const;

    void gameLoop();
    void gameOver();
};

#endif  // ENVIRONMENT_H
