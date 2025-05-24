#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "../genericRobot.h"

class SemiAutoBot:public GenericRobot{
    public:
        void fire(int x, int y) override;
};

#endif