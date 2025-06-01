#ifndef JUMPSEMIAUTOBOT_H
#define JUMPSEMIAUTOBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpSemiAutoBot: virtual public JumpBot, virtual public SemiAutoBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        JumpSemiAutoBot(GenericRobot* g) : JumpBot(g), SemiAutoBot(g), GenericRobot(*g) {
            selfLog("JumpSemiAutoBot created with jump amount: " + to_string(jumpAmount));
        };
};
#endif