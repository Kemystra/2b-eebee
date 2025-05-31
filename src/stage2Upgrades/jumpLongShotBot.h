#ifndef JUMPLONGSHOTBOT_H
#define JUMPLONGSHOTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpLongShotBot: virtual public JumpBot, virtual public LongShotBot{
    public:
        void thinkAndExecute() override;
        JumpLongShotBot(GenericRobot* g) : JumpBot(g), LongShotBot(g), GenericRobot(*g) {
            selfLog("JumpLongShotBot created with jump amount: " + to_string(jumpAmount));
        };
};
#endif