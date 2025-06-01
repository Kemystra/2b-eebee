#ifndef JUMPBOT_H
#define JUMPBOT_H

#include "../genericRobot.h"
#include "../environment.h"
class JumpBot:virtual public GenericRobot{
    public:
        void jump(Vector2D target); // Jump to a target position
        JumpBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("JumpBot created with jump amount: " + to_string(jumpAmount));
        };
        void thinkAndExecute() override;
        Vector2D randomizeJump();
        int getJumpAmount() const;
    protected:
        int jumpAmount = 3;
};


#endif