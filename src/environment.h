#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <memory>
#include <vector>
#include <queue>
#include <string>

#include "abstractRobot/robot.h"
#include "logger.h"
#include "vector2d.h"
#include "genericRobot.h"

using namespace std;


// Class to store everything related to the overall environment stuff
// Implement environment checking here
class Environment {
private:
    // We cannot use raw pointer here
    // See the constructor implementation in environment.cpp
    vector<unique_ptr<GenericRobot>> robotList;

    // First robot in, first robot out
    queue<unique_ptr<GenericRobot>> respawnQueue;

    // Robots to upgrade


    Logger* logger;

    // Width and height of the battleground
    Vector2D dimension;

    // 2D grid for marks (fire, line, etc.)
    vector<vector<char>> grid;

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
    // Fire/line mark methods
    void placeFireMark(int x, int y);
    void drawLine(int x1, int y1, int x2, int y2);
        // Remove all fire marks from the grid
    void clearFireMarks();

    // Remove all line marks from the grid
    void clearLineMarks();
    
    bool isRobotHere(Vector2D positionToCheck) const;
    bool isPositionAvailable(Vector2D positionToCheck) const;
    bool isWithinBounds(Vector2D positionToCheck) const;

    GenericRobot* getRobotAtPosition(Vector2D positionToCheck);
    void printwelcomemessage() const;
    // Print the map grid with robot positions and cardinal directions
    void printMap() const;

    void gameLoop();
    void gameOver();

    void notifyKill(GenericRobot* killer, GenericRobot* victim, DeadState deadState);
    vector<unique_ptr<GenericRobot>>::iterator getRobotIndex(GenericRobot* robot);
};

#endif  // ENVIRONMENT_H
