#include <iostream>

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
