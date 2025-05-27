#include "scoutBot.h"
#include "../environment.h"

vector<Vector2D> ScoutBot::scout(){
    vector<Vector2D> scoutedBots;
    selfLog("Scouting the environment.");
    // gets all the robots in env, and iterates through each of em
    for (const auto& robot : environment->getAllRobots()) {
        Vector2D pos = robot->getPosition();
        Vector2D selfPos = this->getPosition();
        if (pos.x != selfPos.x || pos.y != selfPos.y) { // Don't scout self
            scoutedBots.push_back(pos);
            selfLog("Found robot at: (" + to_string(pos.x) + ", " + to_string(pos.y) + ")");
        }
    }
    return scoutedBots;
}