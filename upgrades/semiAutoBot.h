#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "../src/genericRobot.h"

class ThirtyShotBot:public GenericRobot{
    public:
        void fire(int x, int y) override;
};

#endif