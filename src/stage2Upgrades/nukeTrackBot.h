#ifndef NUKETRACKBOT_H
#define NUKETRACKBOT_H

#include "../stage1Upgrades/nukeBot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../genericRobot.h"

class NukeTrackBot : public NukeBot, public TrackBot {
    public: 
        NukeTrackBot(GenericRobot* g) : GenericRobot(*g), NukeBot(g), TrackBot(g) {
            selfLog("NukeTrackBot created with track count: " + to_string(trackCount));
        };
        void thinkAndExecute() override;
};

#endif 