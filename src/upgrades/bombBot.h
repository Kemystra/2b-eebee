#ifndef BOMBBOT_H
#define BOMBBOT_H

#include "../genericRobot.h"

class BombBot:public GenericRobot{
    private:
        vector<int> areaOfEffect = {3,3};
    public:
        void fire(int x, int y) override;
};

#endif