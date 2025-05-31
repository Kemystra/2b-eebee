#ifndef JUMPBOMBBOT_H
#define JUMPBOMBBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpBombBot: virtual public BombBot, virtual public JumpBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        JumpBombBot(GenericRobot* g) : BombBot(g), JumpBot(g), GenericRobot(*g) {
            selfLog("JumpBombBot created with jump amount: " + to_string(jumpAmount));
        };
};
#endif