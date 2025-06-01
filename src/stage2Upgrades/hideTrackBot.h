#ifndef HIDETRACKBOT_H
#define HIDETRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideTrackBot: virtual public HideBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        HideTrackBot(GenericRobot* g) : HideBot(g), TrackBot(g), GenericRobot(*g) {
            selfLog("HideTrackBot created");
        };
};
#endif