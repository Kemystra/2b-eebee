#ifndef THIRTYSHOTSCOUTBOT_H
#define THIRTYSHOTSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class ThirtyShotScoutBot: virtual public ThirtyShotBot, virtual public ScoutBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        ThirtyShotScoutBot(GenericRobot* g) : ThirtyShotBot(g), ScoutBot(g), GenericRobot(*g) {
            selfLog("ThirtyShotScoutBot created with scout count: " + to_string(scoutCount));
        };
};
#endif