#include "semiAutoBot.h"

void SemiAutoBot::fire(int x, int y){
    Vector2D target(x, y);
    Vector2D targetAbsolutePosition = position + target;

    // Draw the fire trajectory (track) from current position to target
    environment->drawLine(position.x, position.y, targetAbsolutePosition.x, targetAbsolutePosition.y);
    // Place a fire mark at the target
    environment->placeFireMark(targetAbsolutePosition.x, targetAbsolutePosition.y);

    // Print the map with marks
    environment->printMap();

    // Clear all fire and line marks after printing
    environment->clearFireMarks();
    environment->clearLineMarks();

    GenericRobot* targetRobot = environment->getRobotAtPosition(targetAbsolutePosition);

    // If it's hidden, set the probability to impossible
    bool targetIsVisible = targetRobot->getIsVisible();
    double dieProbability = targetIsVisible ? 0.7 : 0;

    selfLog("Fired at " + to_string(targetAbsolutePosition.x) + ", " + to_string(targetAbsolutePosition.y));
    // call die() directly
    // Allow flexibility of 'killing' the oponent later since we can set the probability
    // fires 3 bullets and randomise each time
    for (int i =0; i<3; i++){
        if(randomBool(dieProbability)) {
            targetRobot->die();
            selfLog("Killed " + targetRobot->getName() + " at " + to_string(targetAbsolutePosition.x) + ", " + to_string(targetAbsolutePosition.y));
            environment->notifyKill(this, targetRobot);
            break; // Exit after the first successful hit
        }
        else {
            selfLog("Missed " + targetRobot->getName() + " at " + to_string(targetAbsolutePosition.x) + ", " + to_string(targetAbsolutePosition.y));
        }
    }
    shellCount--;
}