#include "environment.h"
#include "abstractRobot/robot.h"
#include "genericRobot.h"
#include "vector2d.h"

#include <algorithm>
#include <memory>
#include <random>

// Needed for sleep function
#include <chrono>
#include <thread>

using namespace std;

Environment::Environment(
    int maxStep,
    Vector2D dimension,
    vector<RobotParameter> robotParams,
    Logger* logger
) {
    this->maxStep = maxStep;
    this->dimension = dimension;

    // Temporary RNG to seed the robots RNG
    // We are using another RNG instead of just passing the same seed
    // so that all the robots won't do the same thing at the same time
    mt19937_64 rng(69420);

    this->logger = logger;

    // By default, C++ store objects on the stack memory
    // Every time an object goes out-of-scope (here, on each loop iteration), it will be destroyed
    // Using raw pointers, all the robots that are created will be destroyed except the last one.
    //
    // To avoid that you have to store them on the heap memory (using the 'new' keyword)
    // Problem with that is we have to 'delete' the objects afterwards
    // which is a massive pain in the ass.
    //
    // Instead, we are going to use 'smart pointers' (here, it is unique_ptr)
    // It will automatically 'delete' our object when the program ends.
    //
    // Note that unique_ptr also means that Environment now 'owns' the robots object
    // Important note for later.
    for (const RobotParameter &param : robotParams) {
        GenericRobot robot(param, this, rng(), logger);

        this->robotList.push_back(make_unique<GenericRobot>(robot));
    }
}

void Environment::gameLoop() {
    while (maxStep > step) {
        for (unique_ptr<GenericRobot> &robot : this->robotList) {
            printMap();
            robot->thinkAndExecute();
            this_thread::sleep_for(
                chrono::milliseconds(robotActionInterval)
            );
        }

        if (robotList.size() == 0)
            gameOver();

        step++;

        this_thread::sleep_for(
            chrono::milliseconds(stepInterval)
        );
    }

    gameOver();
}

void Environment::gameOver() {
    cout << "Game Over" << endl;
}

bool Environment::isRobotHere(Vector2D positionToCheck) const {
    for (const unique_ptr<GenericRobot> &robot : this->robotList) {
        if (robot->getPosition() == positionToCheck)
            return true;
    }

    return false;
}

GenericRobot* Environment::getRobotAtPosition(Vector2D positionToCheck) {
    for (unique_ptr<GenericRobot> &robot : this->robotList) {
        if (robot->getPosition() == positionToCheck)

            // To return the raw pointer to the object, use get()
            // DO NOT RETURN THE unique_ptr ITSELF
            return robot.get();
    }

    return nullptr;
}

bool Environment::isPositionAvailable(Vector2D positionToCheck) const {
    // only 1 robot at 1 position
    if (isRobotHere(positionToCheck))
        return false;

    // Cannot go out of bounds of the battleground
    if(positionToCheck.x > dimension.x || positionToCheck.x < 0)
        return false;

    if(positionToCheck.y > dimension.y || positionToCheck.y < 0)
        return false;

    return true;
}

void Environment::printMap() const {
    // Print column headers (X axis)
    cout << "   ";
    for (int x = 0; x < dimension.x; ++x) {
        cout << x << " ";
    }
    cout << "\n";
    for (int y = 0; y < dimension.y; ++y) {
        // Print row header (Y axis)
        cout << y << " |";
        for (int x = 0; x < dimension.x; ++x) {
            Vector2D pos(x, y);
            bool found = false;
            for (const unique_ptr<GenericRobot> &robot : robotList) {
                if (robot->getPosition() == pos) {
                    cout << robot->getSymbol() << " ";
                    found = true;
                    break;
                }
            }
            if (!found) cout << ". ";
        }
        cout << "|\n";
    }
    // Print cardinal directions
    cout << "\nN (up)\nS (down)\nE (right)\nW (left)\n";
}

void Environment::notifyKill(GenericRobot* killer, GenericRobot* victim, DeadState deadState) {
    // find() returns an iterator type with a long typename that I can't even find
    // just gonna use auto here lol
    auto victim_iterator = find(robotList.begin(), robotList.end(), victim);
    auto killer_iterator = find(robotList.begin(), robotList.end(), killer);

    // Later need to add upgrade mechanism

    // If respawn move to respawn queue, else just delete urself lol
    switch (deadState) {
        case DeadState::Respawn:
            respawnQueue.push(*victim_iterator);
            robotList.erase(victim_iterator);
        break;

        case DeadState::Dead:
            robotList.erase(victim_iterator);
        break;
    }
}
