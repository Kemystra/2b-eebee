#include "jumpBombTrackBot.h"

void JumpBombTrackBot::thinkAndExecute() {
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
            bomb(closestRobotPosition.x, closestRobotPosition.y);
    }
    Vector2D nextMove;
    if (getJumpAmount() > 0) {
        // Randomly decide to jump or not
        bool useJump = randomBool(0.5);
        if (useJump) {
            nextMove = randomizeJump();
            this->jumpAmount--;
        }
        else{
            if (closestRobotPosition == Vector2D::ZERO)
                nextMove = randomizeMove();
            else {
                nextMove = closestRobotPosition.normalized() * movementRange;
            }
        }
        
    }
    else{
        
        if (closestRobotPosition == Vector2D::ZERO)
            nextMove = randomizeMove();
        else {
            nextMove = closestRobotPosition.normalized() * movementRange;
        }

    }
    move(nextMove.x, nextMove.y);
};