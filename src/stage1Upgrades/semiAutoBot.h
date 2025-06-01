#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "../genericRobot.h"
#include "../environment.h"
class SemiAutoBot:public GenericRobot{
    public:
        SemiAutoBot(GenericRobot* g) : GenericRobot(*g){};
        void fire(int x, int y) override;
};

#endif