#ifndef JUMPBOT_H
#define JUMPBOT_H

#include "../src/genericRobot.h"
class JumpBot:public GenericRobot{
    public:
        void jump(int x, int y);
};


#endif