#ifndef HIDELONGSHOTBOT_H
#define HIDELONGSHOTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideLongShotBot: virtual public HideBot, virtual public LongShotBot{
    public:
        void thinkAndExecute() override;
        HideLongShotBot(GenericRobot* g) : HideBot(g), LongShotBot(g), GenericRobot(*g) {
            selfLog("HideLongShotBot created");
        };
};
#endif