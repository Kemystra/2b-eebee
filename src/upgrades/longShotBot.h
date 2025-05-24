#ifndef LONGSHOTBOT_H
#define LONGSHOTBOT_H

#include "../genericRobot.h"

class LongShotBot:public GenericRobot{
    public:
        void fire(int x, int y) override;
        int getMaxFiringDistance() const override;
};
#endif