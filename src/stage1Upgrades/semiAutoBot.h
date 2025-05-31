#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "../genericRobot.h"

class SemiAutoBot:virtual public GenericRobot{
    public:
        SemiAutoBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("SemiAutoBot created");
        };
        // void fire(int x, int y) override;
};

#endif