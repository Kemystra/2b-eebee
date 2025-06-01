#include "bombBot.h"

void BombBot::bomb(int x, int y){
    selfLog("Bombing at " + to_string(x) + ", " + to_string(y));
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Vector2D targetPosition = Vector2D(x, y) + Vector2D(i, j);
            // IF TARGET IS not self, position is not available cuz got bot, kaboom
            if (targetPosition != Vector2D::ZERO && !(environment->isPositionAvailable(targetPosition))) {
                fire(targetPosition.x, targetPosition.y);
            }
        }
    }
}

void BombBot::thinkAndExecute() {
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
            bomb(closestRobotPosition.x, closestRobotPosition.y);
    }

    Vector2D nextMove;
    if (closestRobotPosition == Vector2D::ZERO)
        nextMove = randomizeMove();
    else {
        nextMove = closestRobotPosition.normalized() * movementRange;
    }

    move(nextMove.x, nextMove.y);
}