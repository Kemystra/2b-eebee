#include <iostream>
#include <fstream>

#include "abstractRobot/robot.h"
#include "environment.h"
#include "logger.h"
using namespace std;


int main (int argc, char *argv[]) {
    // 40x40 grid
    Vector2D dimension(40, 40);
    int maxStep = 100; // or any value you want

    RobotParameter r1 = {"bruh", Vector2D(8,9)};
    RobotParameter r2 = {"shit", Vector2D(34,9)};
    RobotParameter r3 = {"ass", Vector2D(8,23)};

    vector<RobotParameter> robotParams = {
        r1, r2, r3
    }; // Add robots as needed
    Environment env(maxStep, dimension, robotParams);

    env.gameLoop();

    // Read configuration from the input file
    // Initialize the Environment class
    // Initialize random
    //
    // Add robots into Environment's robotList
    // Initialize command line printing
    //
    // Start simulation loop
    // Run Robot::execute_turn() for each robot
    // Re-enter robot if dead
    // Repeat till no robots left / steps finish
    Logger logger;
    logger.log("Simulation started");
    logger.log("Initializing environment...");
    logger.log("Environment initialized");
    return 0;
}
