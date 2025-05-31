#ifndef JUMPBOT_H
#define JUMPBOT_H

#include "../genericRobot.h"
class JumpBot:public GenericRobot{
    public:
        void jump(Vector2D target); // Jump to a target position
    protected:
        int jumpAmount = 3;
};


#endif