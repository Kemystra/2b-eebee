#include <iostream>
#include <fstream>

#include "abstractRobot/robot.h"

#include "environment.h"

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
    vector<RobotParameter> robotParams;
    for (const auto& info : paramReader.getRobots()) {
        Vector2D pos(info.x, info.y);
        // Use first char of name as symbol, fallback to 'R' if name empty
        char symbol = !info.name.empty() ? info.name[0] : 'R';
        robotParams.push_back({info.name, pos, symbol});
    }

    Environment env(maxStep, dimension, robotParams, &logger);
    env.printwelcomemessage();

    // Display field size and robot info
    cout << "Robot's initial position (x, y):\n" << endl;
    cout << "Robots:" << endl;
    for (const auto& info : paramReader.getRobots()) {
        cout << "  Type: " << info.type
             << ", Name: " << info.name
             << ", Position (x, y): ";
        if (info.isRandomPosition)
            cout << "(random)";
        else
            cout << "(" << info.x << ", " << info.y << ")";
        cout << endl;
    }

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
