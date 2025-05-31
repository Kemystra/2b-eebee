#ifndef HIDEBOMBBOT_H
#define HIDEBOMBBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideBombBot: virtual public BombBot, virtual public HideBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        HideBombBot(GenericRobot* g) : BombBot(g), HideBot(g), GenericRobot(*g) {
            selfLog("BombHideBot created");
        };
};
#endif