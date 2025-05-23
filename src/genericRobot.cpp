#include <iostream>
#include <string>
#include <vector>

#include "genericRobot.h"
#include "abstractRobot/robot.h"
#include "environment.h"
#include "vector2d.h"

using namespace std;


string GenericRobot::getName() const {
    return this->name;
}

GenericRobot::GenericRobot(
    Vector2D initialPosition,
    string name,
    Environment* env
) {
    this->position = initialPosition;
    this->name = name;
    this->environment = env;
}

DeadState GenericRobot::die() {
    if (respawnCountLeft == 0)
        return DeadState::Dead;

    respawnCountLeft--;
    return DeadState::Respawn;
}

void GenericRobot::gotHit() {
    // Calculate 70% probability
    // If hit, then die mf

    this->die();
}

void GenericRobot::executeTurn() {
    cout << "Execute turn" << endl;

    // Generate later
    Vector2D nextLookPosition(1,1);

    vector<Vector2D> lookResult = look(nextLookPosition.x, nextLookPosition.y);

    for (const Vector2D &pos : lookResult) {
        fire(pos.x, pos.y);
    }
}

vector<Vector2D> GenericRobot::look(int x, int y) {
    vector<Vector2D> lookResult = {};
    Vector2D center(x, y);

    // Loop through a 3x3 square around center
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Vector2D currentLookAbsolutePosition = position + center + Vector2D(i, j);

            lookResult.push_back(
                environment->isRobotHere(currentLookAbsolutePosition)
            );
        }
    }

    return lookResult;
}

void GenericRobot::fire(int x, int y) {
    Vector2D target(x, y);
    Vector2D targetAbsolutePosition = position + target;

    GenericRobot* targetRobot = environment->getRobotAtPosition(targetAbsolutePosition);

    targetRobot->gotHit();
    shellCount--;
}

void GenericRobot::move(int x, int y) {
    position += Vector2D(x,y);
}

void GenericRobot::think() {

}

char GenericRobot::getSymbol() const {
    // Use the first letter of the robot's name as its symbol (capitalized)
    return name.empty() ? '?' : toupper(name[0]);
}

Vector2D GenericRobot::getPosition() const {
    return position;
}
