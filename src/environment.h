#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <memory>
#include <vector>
#include <queue>
#include <set>
#include <string>

#include "abstractRobot/robot.h"
#include "logger.h"
#include "vector2d.h"
#include "genericRobot.h"

using namespace std;


// Alternative name for this useful yet ugly ass type
// This is an iterator, think of it like a fancy array index
typedef vector<unique_ptr<GenericRobot>>::iterator RobotPtrIterator;

// Class to store everything related to the overall environment stuff
// Implement environment checking here
class Environment {
private:
    // We cannot use raw pointer here
    // See the constructor implementation in environment.cpp
    vector<unique_ptr<GenericRobot>> robotList;

    // First robot in, first robot out (on each turn)
    queue<unique_ptr<GenericRobot>> respawnQueue;

    // Robots to upgrade
    // We want to maintain the order of the robot if they are upgraded
    // So we only store the iterator rather than the robot itself
    // We use set to avoid adding the same robots multiple time
    set<RobotPtrIterator> robotsToUpgrade;

    set<RobotPtrIterator> robotsToRespawn;
    set<RobotPtrIterator> robotsToDie;

    Logger* logger;

    // Width and height of the battleground
    Vector2D dimension;

    // 2D grid for marks (fire, line, etc.)
    vector<vector<char>> grid;

    int maxStep;
    int step = 0;

    // See gameLoop() for explanation
    int currentRobotLength;

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

    Vector2D getGridSize() const;

    GenericRobot* getRobotAtPosition(Vector2D positionToCheck) const;
    void printwelcomemessage() const;

    // Print the map grid with robot positions and cardinal directions
    void printMap() const;

    void gameLoop();
    void gameOver();

    void notifyKill(GenericRobot* killer, GenericRobot* victim);
    RobotPtrIterator getRobotIterator(GenericRobot* robot);

    void applyRobotUpgrades();
    void applyRobotRespawn();
    void applyRobotDie();

    const vector<GenericRobot*> getAllAvailableRobots() const;
};

#endif  // ENVIRONMENT_H
