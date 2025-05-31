#ifndef JUMPLANDMINEBOT_H
#define JUMPLANDMINEBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpLandmineBot: virtual public JumpBot, virtual public LandmineBot {
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        JumpLandmineBot(GenericRobot* g) : JumpBot(g), LandmineBot(g), GenericRobot(*g) {
            selfLog("JumpLandmineBot created with jump amount: " + to_string(jumpAmount));
        };
};
#endif