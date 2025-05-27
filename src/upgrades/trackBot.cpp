#include "trackBot.h"
#include "../environment.h"

void TrackBot::track(Vector2D positionOfRobot) {
    // Check if the position is within the bounds of the environment
    if (!environment->isWithinBounds(positionOfRobot)) {
        selfLog("Cannot track robot at (" + to_string(positionOfRobot.x) + ", " + to_string(positionOfRobot.y) + ") - out of bounds.");
        return;
    }
    if (environment->isRobotHere(positionOfRobot)) {
        // if theres a robot at the position, get it's pointer and save it to trackedBots
        trackedBots.push_back(environment->getRobotAtPosition(positionOfRobot));
        selfLog("Tracked robot " + trackedBots.back()->getName() + " at (" + to_string(positionOfRobot.x) + ", " + to_string(positionOfRobot.y) + ")");
    } else {
        selfLog("No robot found at (" + to_string(positionOfRobot.x) + ", " + to_string(positionOfRobot.y) + ") to track.");
    }
}