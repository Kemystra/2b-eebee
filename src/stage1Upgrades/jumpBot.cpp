#include "jumpBot.h"
#include "../environment.h"

void JumpBot::thinkAndExecute() {
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
            fire(closestRobotPosition.x, closestRobotPosition.y);
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
}

Vector2D JumpBot::randomizeJump() {
    // Generate x and y between -jumpAmount and jumpAmount
    Vector2D gridSize = environment->getGridSize();
    uniform_int_distribution<int> next_x_generator(0, gridSize.x - 1);
    uniform_int_distribution<int> next_y_generator(0, gridSize.y - 1);

    bool validJump = false;
    int next_x;
    int next_y;

    // Keep generating next jump
    // until a valid one is found
    while (!validJump) {
        next_x = next_x_generator(rng);
        next_y = next_y_generator(rng);

        validJump = environment->isPositionAvailable(
            Vector2D(next_x, next_y)
        );
    }
    Vector2D newPosition = Vector2D(next_x, next_y)- this->getPosition();
    return newPosition;
}

int JumpBot::getJumpAmount() const {
    return this->jumpAmount;
}
