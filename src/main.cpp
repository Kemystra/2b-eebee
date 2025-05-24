#include <iostream>
#include <fstream>

#include "abstractRobot/robot.h"
#include "environment.h"

using namespace std;


int main (int argc, char *argv[]) {
    // 40x40 grid
    Vector2D dimension(40, 40);
    int maxStep = 100; // or any value you want

    RobotParameter r1 = {"bruh", Vector2D(8,9), 'A'};
    RobotParameter r2 = {"shit", Vector2D(34,9), 'B'};
    RobotParameter r3 = {"ass", Vector2D(8,23), 'C'};
    RobotParameter r4 = {"ass", Vector2D(2,23), 'D'};
    RobotParameter r5 = {"ass", Vector2D(10,23), 'E'};
    RobotParameter r6 = {"ass", Vector2D(8,33), 'F'};
    RobotParameter r7 = {"ass", Vector2D(15,23), 'G'};
    RobotParameter r8 = {"ass", Vector2D(11,1), 'H'};
    RobotParameter r9 = {"ass", Vector2D(0,0), 'I'};
    RobotParameter r10 = {"ass", Vector2D(19,11), 'J'};

    vector<RobotParameter> robotParams = {
        r1, r2, r3, r4, r5, r6, r7, r8, r9, r10
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
    
    return 0;
}
