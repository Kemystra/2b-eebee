#ifndef THIRTYSHOTBOT_H
#define THIRTYSHOTBOT_H

#include "../genericRobot.h"

class ThirtyShotBot:public GenericRobot{
    public:
        ThirtyShotBot(GenericRobot* g) : GenericRobot(*g) {
            setShellCount();
        };
        void setShellCount();
};

#endif