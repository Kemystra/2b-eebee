#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "../genericRobot.h"
#include "../environment.h"
class SemiAutoBot:virtual public GenericRobot{
    public:
        SemiAutoBot(GenericRobot* g) : GenericRobot(*g){};
        int getBulletsPerShot() const override;
};

#endif