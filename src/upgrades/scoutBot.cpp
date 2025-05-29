#include "scoutBot.h"
#include "../environment.h"

vector<Vector2D> ScoutBot::scout(){
    vector<Vector2D> scoutedBots;
    selfLog("Scouting the environment.");
    // gets all the robots in env, and iterates through each of em
    for (const auto& robot : environment->getAllRobots()) {
        Vector2D pos = robot->getPosition();
        Vector2D selfPos = this->getPosition();
        Vector2D relativePosition = selfPos - pos;
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
    int maxFireDistance = getMaxFiringDistance();
    int bulletsPerShot = getBulletsPerShot();

    // Generate x and y between -1, 0, or 1
    // Note that we only generate integers here
    uniform_int_distribution<int> next_x_generator(this->movementRange[0], this->movementRange[1]);
    uniform_int_distribution<int> next_y_generator(this->movementRange[0],this->movementRange[1]);

    // Will be used for look() and move()
    int next_x = 0;
    int next_y = 0;

    bool validLookCenter = false;
    while (!validLookCenter) {
        next_x = next_x_generator(rng);
        next_y = next_y_generator(rng);

        // Center of vision must be within bounds
        // simply for efficiency
        validLookCenter = environment->isWithinBounds(Vector2D(next_x, next_y));
    }

    if (scoutCount>0){
        useScout = randomBool(0.5);  
    }
    
    vector<Vector2D> lookResult = useScout? scout() : look(next_x,next_y);

    for (const Vector2D &pos : lookResult) {
        selfLog("Robot found at: ("+ to_string(pos.x)+ ", " + to_string(pos.y) + ")");
        int distance = calcDistance(pos);
        if (distance > maxFireDistance)
            continue;

        for (int i = 0; i < bulletsPerShot; i++) {
            selfLog("Attemting to fire at: (" + to_string(pos.x)+ ", " + to_string(pos.y) + ")");
            fire(pos.x, pos.y);
        }
    }

    bool validMovement = false;

    // Keep generating next movement
    // until a valid one is found
    while (!validMovement) {
        next_x = next_x_generator(rng);
        next_y = next_y_generator(rng);

        validMovement = environment->isPositionAvailable(
            this->position + Vector2D(next_x, next_y)
        );
    }

    move(next_x, next_y);
};