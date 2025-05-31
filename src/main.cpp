#include <iostream>
#include <sstream>

#include "environment.h"
#include "genericRobot.h"

#include "logger.h"
#include "ParameterFileReader.h"

using namespace std;


int main (int argc, char *argv[]) {

    // Read parameters from parameter.txt
    ParameterFileReader paramReader;
    if (!paramReader.readFile("parameter.txt")) {
        cerr << "Failed to read parameter.txt" << endl;
        return 1;
    }

    int m = paramReader.getM();
    int n = paramReader.getN();
    int maxStep = paramReader.getSteps();
    Vector2D dimension(m, n);

    // Init logger
    Logger logger;

    // Convert RobotInfo to RobotParameter
    vector<RobotParameter> robotParams = paramReader.getRobots();

    Environment env(maxStep, dimension, robotParams, &logger);
    env.printwelcomemessage();

    // Display field size and robot info
    logger.log("Robot's initial position:\n");
    logger.log("Robots:");
    for (const auto& info : paramReader.getRobots()) {
        std::ostringstream oss;
        oss << "  Type: " << info.type
            << ", Name: " << info.name
            << ", Position (x, y): ";
        oss << "(" << info.position.x << ", " << info.position.y << ")";
        logger.log(oss.str());
    }
    logger.log("");

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
    return 0;
}
