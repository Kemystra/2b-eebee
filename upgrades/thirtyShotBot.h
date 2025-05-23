#ifndef THIRTYSHOTBOT_H
#define THIRTYSHOTBOT_H

#include "../src/genericRobot.h"

class ThirtyShotBot:public GenericRobot{
    public:
        void fire(int x, int y) override;
        int getBulletsPerShot() const override;
};
#endif