#ifndef BOMBBOT_H
#define BOMBBOT_H

#include "../genericRobot.h"

class BombBot:virtual public GenericRobot{
    private:
        vector<int> areaOfEffect = {3,3};
    public:
        BombBot(GenericRobot* g) : GenericRobot(*g) {};
        // void fire(int x, int y) override;
};

#endif