#include "trackBot.h"
#include "../environment.h"

void TrackBot::track(Vector2D positionOfRobot) {
    positionOfRobot = this->getPosition() + positionOfRobot;
    if (environment->isRobotHere(positionOfRobot)) {
        // if theres a robot at the position, get it's pointer and save it to trackedBots
        trackedBots.push_back(environment->getRobotAtPosition(positionOfRobot));
        selfLog("Tracked robot " + trackedBots.back()->getName() + " at (" + to_string(positionOfRobot.x) + ", " + to_string(positionOfRobot.y) + ")");
    } else {
        selfLog("No robot found at (" + to_string(positionOfRobot.x) + ", " + to_string(positionOfRobot.y) + ") to track.");
    }
}

void TrackBot::thinkAndExecute(){
    int maxFireDistance = getMaxFiringDistance();
    int bulletsPerShot = getBulletsPerShot();
    // Generate x and y between -1, 0, or 1
    // Note that we only generate integers here
    uniform_int_distribution<int> next_x_generator(this->movementRange[0], this->movementRange[1]);
    uniform_int_distribution<int> next_y_generator(this->movementRange[0],this->movementRange[1]);

    // Will be used for look() and move()
    int next_x = 0;
    int next_y = 0;

    bool validLookCenter = false;
    while (!validLookCenter) {
        next_x = next_x_generator(rng);
        next_y = next_y_generator(rng);

        // Center of vision must be within bounds
        // simply for efficiency
        validLookCenter = environment->isWithinBounds(Vector2D(next_x, next_y));
    }

    Vector2D closestRobotCoordinates;
    for(const GenericRobot* robot: trackedBots){
        // get the relative coordinates of the current iterated bot
        Vector2D currentRobotRelativeCoordinate = this->getPosition() - robot->getPosition();
        // if closest robot is further than current robot, then update closest robot
        // compare the closest robot's coords, and the current iterated robot's coords
        if(calcDistance(closestRobotCoordinates)>calcDistance(currentRobotRelativeCoordinate)){
            closestRobotCoordinates = currentRobotRelativeCoordinate;
        }
    }

    vector<Vector2D> lookResult = look(next_x, next_y);
    for (const Vector2D &pos : lookResult) {
        selfLog("Robot found at: ("+ to_string(pos.x)+ ", " + to_string(pos.y) + ")");
        if(trackedBots.size()<3){
            // if still can track bots, randomise to decide to track or not
            bool trackOrNot = randomBool(0.5);
            if (trackOrNot){
                //if want track, track it
                track(pos);
            }
        }
        if(calcDistance(pos)<calcDistance(closestRobotCoordinates)){
            closestRobotCoordinates = pos;
        };
    }

    if(calcDistance(closestRobotCoordinates) < maxFireDistance){
        selfLog("Attemting to fire at: (" + to_string(closestRobotCoordinates.x)+ ", " + to_string(closestRobotCoordinates.y) + ")");
        fire(closestRobotCoordinates.x, closestRobotCoordinates.y);
    }
    bool validMovement = false;

    // Keep generating next movement
    // until a valid one is found
    while (!validMovement) {
        next_x = next_x_generator(rng);
        next_y = next_y_generator(rng);

        validMovement = environment->isPositionAvailable(
            this->position + Vector2D(next_x, next_y)
        );
    }
    // if closestRobotCoordinates is further or equal to next_x, then move towards closest robot anyways, else just randomly move 
    Vector2D robotPosition = this->getPosition();
    if (robotPosition.distance(closestRobotCoordinates) >= Vector2D(next_x, next_y).distance(Vector2D(0, 0))) {
        next_x = closestRobotCoordinates.x;
        next_y = closestRobotCoordinates.y;
    }
    move(next_x, next_y);
}