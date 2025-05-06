#include <iostream>
#include <vector>

#include "genericRobot.h"
#include "vector2d.h"

using namespace std;


GenericRobot::GenericRobot(Vector2D initialPosition) {
    this->position = initialPosition;
}

void GenericRobot::die() {
    cout << "You're dead" << endl;
}

void GenericRobot::gotHit() {
    cout << "Got hit bruh" << endl;
}

void GenericRobot::executeTurn() {
    cout << "Oompa Loompa" << endl;
}

vector<Vector2D> GenericRobot::look(Vector2D center) {
    vector<Vector2D> lookResult = {};

    // Loop through a 3x3 square around center
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Vector2D currentLookAbsolutePosition = position + center + Vector2D(i, j);

            // Ask the Environment if there's Robot here
            // If yes, add it to result
        }
    }

    return lookResult;
}

void GenericRobot::fire(Vector2D target) {
    Vector2D targetAbsolutePosition = position + target;
    // Get robot from Environment
    GenericRobot robot(Vector2D(0,0));

    robot.gotHit();
    shellCount--;
}

void GenericRobot::move(Vector2D destination) {
    position += destination;
}
