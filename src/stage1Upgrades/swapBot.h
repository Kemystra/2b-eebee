#ifndef SWAPBOT_H
#define SWAPBOT_H

#include "../genericRobot.h"

class SwapBot:public GenericRobot{
    public:
        void swapPosition();   //switch position with random bot
};

#endif