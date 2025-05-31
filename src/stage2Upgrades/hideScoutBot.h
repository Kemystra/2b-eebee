#ifndef HIDESCOUTBOT_H
#define HIDESCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideScoutBot: virtual public HideBot, virtual public ScoutBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        HideScoutBot(GenericRobot* g) : HideBot(g), ScoutBot(g),GenericRobot(*g) {
            selfLog("HideScoutBot created");
        };
};
#endif