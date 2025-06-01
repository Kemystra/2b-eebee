#ifndef BOMBBOT_H
#define BOMBBOT_H

#include "../genericRobot.h"
#include "../environment.h"
class BombBot:virtual public GenericRobot{
    public:
        BombBot(GenericRobot* g) : GenericRobot(*g) {};
        void bomb(int x, int y);
        void thinkAndExecute() override;
};

#endif