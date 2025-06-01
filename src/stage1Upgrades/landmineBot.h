#ifndef LANDMINEBOT_H
#define LANDMINEBOT_H

#include "../genericRobot.h"

class LandmineBot:virtual public GenericRobot{
    public:
        LandmineBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("LandmineBot created");
        };
        // void fire(int x, int y) override;
};

#endif