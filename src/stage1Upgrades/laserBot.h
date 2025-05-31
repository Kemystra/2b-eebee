#ifndef LASERBOT_H
#define LASERRBOT_H

#include "../genericRobot.h"

class LaserBot:virtual public GenericRobot{
    public:
        LaserBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("LaserBot created");
        };
};

#endif