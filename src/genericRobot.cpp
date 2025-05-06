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
    // Calculate 70% probability
    // If hit, then die mf

    this->die();
}

void GenericRobot::executeTurn() {
    cout << "Execute turn" << endl;

    // Generate later
    Vector2D nextLookPosition(0,0);

    vector<Vector2D> lookResult = look(nextLookPosition);

    for (const Vector2D &pos : lookResult) {
        fire(pos);
    }
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
