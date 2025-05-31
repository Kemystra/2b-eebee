#ifndef HIDELASERBOT_H
#define HIDELASERBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideLaserBot: virtual public HideBot, virtual public LaserBot{
    public:
        void thinkAndExecute() override;
        HideLaserBot(GenericRobot* g) : HideBot(g), LaserBot(g), GenericRobot(*g) {
            selfLog("HideLaserBot created");
        };
};
#endif