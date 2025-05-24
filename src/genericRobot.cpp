#include <cstdint>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "genericRobot.h"
#include "abstractRobot/robot.h"
#include "vector2d.h"
#include "environment.h"

using namespace std;


GenericRobot::GenericRobot(
    RobotParameter robotParam,
    Environment* env,
    uint_fast64_t rngSeed
) {
    this->position = robotParam.position;
    this->name = robotParam.name;
    this->symbol = robotParam.symbol;

    this->environment = env;

    // A seed initialize the random number generator (RNG)
    // The advantage is that if we gave it the same seed
    // it will always generate the same sequence of random numbers
    this->rng = mt19937_64(rngSeed);

}

DeadState GenericRobot::die() {
    if (respawnCountLeft == 0)
        return DeadState::Dead;

    respawnCountLeft--;
    return DeadState::Respawn;
}

void GenericRobot::gotHit() {
    // Die probability is 70%, or 0.7
    if (randomBool(0.7))
        this->die();
}

void GenericRobot::thinkAndExecute() {
    cout << "Execute turn" << endl;

    // Fucking redundant, but needed since inheritance REEEE-
    int maxFireDistance = getMaxFiringDistance();
    int bulletsPerShot = getBulletsPerShot();

    // Generate later
    Vector2D nextLookPosition(1,1);

    vector<Vector2D> lookResult = look(nextLookPosition.x, nextLookPosition.y);

    for (const Vector2D &pos : lookResult) {
        int distance = this->position.distance(pos);

        if (distance > maxFireDistance)
            continue;

        for (int i = 0; i < bulletsPerShot; i++) {
            fire(pos.x, pos.y);
        }
    }

    // Generate x and y between -1, 0, or 1
    // Note that we only generate integers here
    uniform_int_distribution<int> next_x(-1,1);
    uniform_int_distribution<int> next_y(-1,1);

    move(next_x(rng), next_y(rng));
}

vector<Vector2D> GenericRobot::look(int x, int y) {
    vector<Vector2D> lookResult = {};

    // Loop through a 3x3 square around center
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            // Center of look coordinate + offset
            Vector2D relativePositionToLook = Vector2D(x, y) + Vector2D(i, j);

            // Same position, but from the whole grid point of view
            Vector2D absolutePositionToLook = this->position + relativePositionToLook;

            if (environment->isRobotHere(absolutePositionToLook))
                lookResult.push_back(relativePositionToLook);
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

int GenericRobot::getBulletsPerShot() const {
    return 1;
}

int GenericRobot::getMaxFiringDistance() const {
    return 1;
}

void GenericRobot::move(int x, int y) {
    position += Vector2D(x,y);
}

string GenericRobot::getName() const {
    return this->name;
}

char GenericRobot::getSymbol() const {
    return this->symbol;
}

Vector2D GenericRobot::getPosition() const {
    return position;
}

// No upgrades, so return empty vector
vector<RobotUpgrades> GenericRobot::getUpgrades() const {
    return vector<RobotUpgrades>();
}

void GenericRobot::setShellCount(int newShellCount){
    shellCount = newShellCount;
}

bool GenericRobot::randomBool(double probability) {
    uniform_real_distribution<double> dist(0.0, 1.0);

    // Generate a number between 0 and 1, and check if it's below probability
    // if yes (which depends on the value of probability) return true
    // else return false
    double num = dist(this->rng);
    return num < probability;
}
