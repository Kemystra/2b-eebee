#ifndef THIRTYSHOTBOT_H
#define THIRTYSHOTBOT_H

#include "../genericRobot.h"

class ThirtyShotBot:public GenericRobot{
    public:
        ThirtyShotBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("ThirtyShotBot created with shell count: " + to_string(shellCount));
        };
        // void fire(int x, int y) override;
        void setShellCount(int newShellCount);
};
#endif