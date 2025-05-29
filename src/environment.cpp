#include "environment.h"
#include "abstractRobot/robot.h"
#include "genericRobot.h"
#include "upgrades/upgrades.h"
#include "upgrades/scoutBot.h"
#include "vector2d.h"

#include <memory>
#include <random>

// Needed for sleep function
#include <chrono>
#include <thread>
#include <vector>

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
        GenericRobot* robot = new GenericRobot(param, this, rng(), logger);

        this->robotList.push_back(unique_ptr<GenericRobot>(robot));
    }
}

void Environment::gameLoop() {
    while (maxStep > step) {
        logger->log("Round " + to_string(step));
        logger->log("Applying robot upgrades");
        applyRobotUpgrades();

        // RobotList length tracking
        // We don't loop directly, since robotList might get edited while looping
        // e.g: when robot dies
        currentRobotLength = robotList.size();

        // Actual counter
        int i = 0;
        while (currentRobotLength > 0) {
            unique_ptr<GenericRobot>& robot = robotList[i];

            logger->log(robot->getName() + "'s turn");
            printMap();
            robot->thinkAndExecute();

            this_thread::sleep_for(
                chrono::milliseconds(robotActionInterval)
            );

            currentRobotLength--;
            i++;
        }

        if (robotList.size() == 1) {
            logger->log("Only one bot remains: " + robotList[0]->getName());
            gameOver();
        }

        step++;

        this_thread::sleep_for(
            chrono::milliseconds(stepInterval)
        );
    }

    logger->log("Steps finished");
    gameOver();
}

void Environment::gameOver() {
    logger->log("Game finished");
}

bool Environment::isRobotHere(Vector2D positionToCheck) const {
    return getRobotAtPosition(positionToCheck) != nullptr;
}

GenericRobot* Environment::getRobotAtPosition(Vector2D positionToCheck) const {
    for (const unique_ptr<GenericRobot> &robot : this->robotList) {
        // Skip dead robots
        if (robot->getIsDead())
            continue;

        if (robot->getPosition() == positionToCheck)
            // To return the raw pointer to the object, use get()
            // DO NOT RETURN THE unique_ptr ITSELF
            return robot.get();
    }

    return nullptr;
}

bool Environment::isPositionAvailable(Vector2D positionToCheck) const {
    // Position is available if no robots there and it's within bounds
    return !isRobotHere(positionToCheck) && isWithinBounds(positionToCheck);
}

bool Environment::isWithinBounds(Vector2D positionToCheck) const {
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
    RobotPtrIterator victimIterator = getRobotIterator(victim);
    RobotPtrIterator killerIterator = getRobotIterator(killer);

    // One robot died, so decrement
    currentRobotLength--;

    // Notify the robot on upgrading and check its upgrade-related state
    UpgradeState upgradeState = killer->chosenForUpgrade();
    if (upgradeState == AvailableForUpgrade)
        // Add to upgrade list
        // If already added before (e.g: multiple kills on 1 round),
        // the set data structure will ensure no duplication
        robotsToUpgrade.insert(killerIterator);

    // If respawn move to respawn queue, else just delete urself lol
    switch (deadState) {
        case DeadState::Respawn:
            logger->log("Put " + victimIterator->get()->getName() + " into the respawn queue");
            respawnQueue.push(move(*victimIterator));
            robotList.erase(victimIterator);
        break;

        case DeadState::Dead:
            logger->log(victimIterator->get()->getName() + " won't respawn anymore");
            robotList.erase(victimIterator);
        break;
    }
}

RobotPtrIterator Environment::getRobotIterator(GenericRobot* robot) {
    for (int i = 0; i < robotList.size(); i++) {
        if(robotList[i].get() == robot)
            return robotList.begin() + i;
    }

    // should never happen, will need error class for this
    return robotList.end();
}

// We cannot upgrade the right after kill
// notifyKill() is called while the robot is running thinkAndExecute()
// Upgrading the robot involves destroying the original object and replacing them with a new one
// If the robot is destroyed while thinkAndExecute() is running, it lead to segfault
// So we will only actually upgrade them at the start of each round
void Environment::applyRobotUpgrades() {
    for (const RobotPtrIterator& robotIterator : robotsToUpgrade) {
        // Get the raw robot pointer
        // For some reason you can't access it like normal pointer
        // even though at other places can
        GenericRobot* robotPtr = robotIterator->get();
        logger->log("Upgrading " + robotPtr->getName());

        // Get the pending upgrade
        vector<Upgrade> pendingUpgrades = robotPtr->getPendingUpgrades();

        for (const Upgrade& upgrade : pendingUpgrades) {
            logger->log("Apply " + stringifyUpgrade(upgrade) + " to " + robotPtr->getName());
            // Will apply upgrades later
            GenericRobot* newRobot = new class ScoutBot(robotPtr);

            // Destroy the old GenericRobot, and switch to the new robot
            // Using iterator allow us to edit in-place, so we don't have to push it into robotList
            robotIterator->reset(newRobot);
        }
    }
}

vector<GenericRobot*> Environment::getAllRobots() const {
    vector<GenericRobot*> result;

    for (const unique_ptr<GenericRobot>& robot : robotList) {
        if (!robot->getIsDead())
            result.push_back(robot.get());
    }

    return result;
}
