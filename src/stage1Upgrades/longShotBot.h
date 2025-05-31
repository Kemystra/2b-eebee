#ifndef LONGSHOTBOT_H
#define LONGSHOTBOT_H

#include "../genericRobot.h"

class LongShotBot:public GenericRobot{
    public:
        LongShotBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("LongShotBot created");
        };
        // void fire(int x, int y) override;
        // int getMaxFiringDistance() const override;
};
#endif