#ifndef HIDELANDMINEBOT_H
#define HIDELANDMINEBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideLandmineBot: virtual public HideBot, virtual public LandmineBot{
    public:
        void thinkAndExecute() override;
        HideLandmineBot(GenericRobot* g) : HideBot(g), LandmineBot(g), GenericRobot(*g) {
            selfLog("HideLandmineBot created");
        };
};
#endif