#ifndef HIDENUKETRACKBOT_H
#define HIDENUKETRACKBOT_H

#include "../stage2Upgrades/nukeTrackBot.h"
#include "../stage1Upgrades/stage1Upgrades.h"
class HideNukeTrackBot : public NukeTrackBot, public HideBot {
    public: 
        HideNukeTrackBot(GenericRobot* g) : GenericRobot(*g), NukeTrackBot(g), HideBot(g) {
            selfLog("HideNukeTrackBot created");
        };
        void thinkAndExecute() override;
};

#endif