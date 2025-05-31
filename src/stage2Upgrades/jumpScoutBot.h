#ifndef JUMPSCOUTBOT_H
#define JUMPSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpScoutBot: virtual public JumpBot, virtual public ScoutBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        JumpScoutBot(GenericRobot* g) : JumpBot(g), ScoutBot(g), GenericRobot(*g) {
            selfLog("JumpScoutBot created with jump amount: " + to_string(jumpAmount));
        };
};
#endif