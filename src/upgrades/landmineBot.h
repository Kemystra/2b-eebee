#ifndef LANDMINEBOT_H
#define LANDMINEBOT_H

#include "../genericRobot.h"

class LandmineBot:public GenericRobot{
    public:
        void fire(int x, int y) override;
};

#endif