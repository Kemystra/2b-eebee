#include "trackBot.h"
#include "../environment.h"

#include <sstream>

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
    Vector2D nextLookCenter;
    if (closestRobotPosition == Vector2D::ZERO)
        nextLookCenter = randomizeMove();
    else {
        nextLookCenter = closestRobotPosition.normalized() * seeingRange;
    }

    vector<Vector2D> lookResult = look(nextLookCenter.x, nextLookCenter.y);

    // Reset the closestRobotPosition after look()
    // If no lookResult(), then it won't be set
    // But if there's lookResult, closestRobotPosition will be updated with the closest one
    closestRobotPosition = Vector2D::ZERO;

    for (const Vector2D& pos : lookResult) {
        // If haven't set yet, set it to current look result
        // And skip to compare to the next look result
        if (closestRobotPosition == Vector2D::ZERO) {
            closestRobotPosition = pos;
            continue;
        }

        if(trackedBots.size()<3){
            // if still can track bots, randomise to decide to track or not
            bool trackOrNot = randomBool(0.5);
            if (trackOrNot){
                //if want track, track it
                track(pos);
            }
        }

        // Since the positions are relative, we can use its vector magnitude
        if (closestRobotPosition.magnitude() > pos.magnitude())
            closestRobotPosition = pos;
    }

    for(const GenericRobot* robot: trackedBots){
        // get the relative coordinates of the current iterated bot
        Vector2D relativePos = this->getPosition() - robot->getPosition();
        // if closest robot is further than current robot, then update closest robot
        if(closestRobotPosition.magnitude()>relativePos.magnitude()){
            closestRobotPosition = relativePos;
        }
    }

    ostringstream oss;
    oss << "Closest robot: " << closestRobotPosition;
    selfLog(oss.str());

    int maxFireDistance = getMaxFiringDistance();
    int bulletsPerShot = getBulletsPerShot();

    int distance = calcDistance(closestRobotPosition);
    if (distance <= maxFireDistance && closestRobotPosition != Vector2D::ZERO) {
        for (int i = 0; i < bulletsPerShot; i++)
            fire(closestRobotPosition.x, closestRobotPosition.y);
    }

    Vector2D nextMove;
    if (closestRobotPosition == Vector2D::ZERO)
        nextMove = randomizeMove();
    else {
        nextMove = closestRobotPosition.normalized() * movementRange;
    }

    move(nextMove.x, nextMove.y);
}
