#ifndef LONGSHOTBOT_H
#define LONGSHOTBOT_H

#include "../genericRobot.h"

class LongShotBot:virtual public GenericRobot{
    public:
        LongShotBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("LongShotBot created");
        };
        int getMaxFiringDistance() const override;
        int calcDistance(Vector2D a) const override;
};
#endif