#include "jumpBot.h"
#include "environment.h"

void JumpBot::jump(Vector2D target) {
    // Check if the new position is within the bounds of the environment
    if (environment->isPositionAvailable(target) && jumpAmount > 0) {
        // Move the robot to the new position
        move(target.x, target.y);
        jumpAmount--; // Decrease jump amount after each jump
        selfLog("Jumped to " + to_string(target.x) + ", " + to_string(target.y));
    } else {
        selfLog("Jump failed: Position out of bounds");
    }
}