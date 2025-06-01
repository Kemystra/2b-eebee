#ifndef JUMPLASERBOT_H
#define JUMPLASERBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpLaserBot: virtual public JumpBot, virtual public LaserBot{
    public:
        void thinkAndExecute() override;
        JumpLaserBot(GenericRobot* g) : JumpBot(g), LaserBot(g), GenericRobot(*g) {
            selfLog("JumpLaserBot created with jump amount: " + to_string(jumpAmount));
        };
};
#endif