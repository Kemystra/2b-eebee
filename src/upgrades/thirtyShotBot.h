#ifndef THIRTYSHOTBOT_H
#define THIRTYSHOTBOT_H

#include "../genericRobot.h"

class ThirtyShotBot:public GenericRobot{
    public:
        void fire(int x, int y) override;
        void setShellCount(int newShellCount);
};
#endif