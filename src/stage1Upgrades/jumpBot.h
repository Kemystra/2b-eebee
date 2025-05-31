#ifndef JUMPBOT_H
#define JUMPBOT_H

#include "../genericRobot.h"
class JumpBot:virtual public GenericRobot{
    public:
        void jump(Vector2D target); // Jump to a target position
        void testJump();
        JumpBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("JumpBot created with jump amount: " + to_string(jumpAmount));
        };
    protected:
        int jumpAmount = 3;
};


#endif