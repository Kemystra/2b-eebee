#include "longShotBot.h"

int LongShotBot::calcDistance(Vector2D a) const {
    Vector2D pos = this->getPosition();
    int distance = abs(a.x - pos.x) + abs(a.y - pos.y);
    return distance;
}

int LongShotBot::getMaxFiringDistance() const {
    return 3;
}