#ifndef LONGSHOTSCOUTBOT_H
#define LONGSHOTSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LongShotScoutBot: virtual public LongShotBot, virtual public ScoutBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        LongShotScoutBot(GenericRobot* g) : LongShotBot(g), ScoutBot(g), GenericRobot(*g) {
            selfLog("LongShotScoutBot created with scout count: " + to_string(scoutCount));
        };
};
#endif