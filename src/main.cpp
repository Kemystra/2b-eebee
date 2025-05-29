#include "environment.h"
#include "logger.h"

using namespace std;


int main (int argc, char *argv[]) {
    // 40x40 grid
    Vector2D dimension(40, 40);
    int maxStep = 100; // or any value you want

    // Init logger
    Logger logger;

    RobotParameter r1 = {"ass", Vector2D(8,9), 'A'};
    RobotParameter r2 = {"boobs", Vector2D(34,9), 'B'};
    RobotParameter r3 = {"cunt", Vector2D(8,23), 'C'};
    RobotParameter r4 = {"dick", Vector2D(2,23), 'D'};
    RobotParameter r5 = {"erection", Vector2D(10,23), 'E'};
    RobotParameter r6 = {"fucker", Vector2D(8,33), 'F'};
    RobotParameter r7 = {"gaygyatt", Vector2D(15,23), 'G'};
    RobotParameter r8 = {"horny", Vector2D(11,1), 'H'};
    RobotParameter r9 = {"itty bitty tiddy", Vector2D(0,0), 'I'};
    RobotParameter r10 = {"jesus", Vector2D(19,11), 'J'};

    vector<RobotParameter> robotParams = {
        r1, r2, r3, r4, r5, r6, r7, r8, r9, r10
    }; // Add robots as needed
    Environment env(maxStep, dimension, robotParams, &logger);

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
