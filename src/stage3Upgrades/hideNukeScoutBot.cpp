#include "hideNukeScoutBot.h"

void HideNukeScoutBot::thinkAndExecute() {
    if (nukeCount > 0) {
        bool shouldNuke = randomBool(0.1); // 10% chance to nuke
        if (shouldNuke) {
            nuke();
            nukeCount--;
            // after nuke, just move randomly
            Vector2D nextMove = randomizeMove();
            move(nextMove.x, nextMove.y);
            return; 
        }
    }
    if (scoutCount>0){
        useScout = randomBool(0.5);  
    };
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
    closestRobotPosition = Vector2D::ZERO;

    for (const Vector2D& pos : lookResult) {
        if (closestRobotPosition == Vector2D::ZERO) {
            closestRobotPosition = pos;
            continue;
        }
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

    if (hideAmount > 0) {
        bool useHide = randomBool(0.5);
        if (useHide) {
            hide();
        }
    }
}