#include "scoutBot.h"
#include "../environment.h"

vector<Vector2D> ScoutBot::scout(){
    vector<Vector2D> scoutedBots;
    selfLog("Scouting the environment.");
    // gets all the robots in env, and iterates through each of em
    for (const auto& robot : environment->getAllAvailableRobots()) {
        Vector2D pos = robot->getPosition();
        Vector2D selfPos = this->getPosition();
        Vector2D relativePosition = pos - selfPos;
        if (pos.x != selfPos.x || pos.y != selfPos.y) { // Don't scout self
            scoutedBots.push_back(relativePosition);
            selfLog("Found robot at: (" + to_string(relativePosition.x) + ", " + to_string(relativePosition.y) + ")");
        }
    }
    scoutCount--;
    if (scoutCount == 0){
        // if no more scouts left, set useScout to permanently be false
        useScout = false;
    }
    return scoutedBots;
}

void ScoutBot::thinkAndExecute(){
    if (scoutCount>0){
        useScout = randomBool(0.5);  
    }

    // Decide between scout() or normal look()
    vector<Vector2D> lookResult;
    if (useScout)
        lookResult = scout();
    else {
        Vector2D nextLookCenter;
        if (closestRobotPosition == Vector2D::ZERO)
            nextLookCenter = randomizeMove();
        else {
            nextLookCenter = closestRobotPosition.normalized() * seeingRange;
        }

        lookResult = look(nextLookCenter.x, nextLookCenter.y);
    }
    

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

        // Since the positions are relative, we can use its vector magnitude
        if (closestRobotPosition.magnitude() > pos.magnitude())
            closestRobotPosition = pos;
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
};
