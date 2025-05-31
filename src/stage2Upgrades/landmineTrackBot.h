#ifndef LANDMINETRACKBOT_H
#define LANDMINETRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LandmineTrackBot: virtual public LandmineBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override;
        LandmineTrackBot(GenericRobot* g) : LandmineBot(g), TrackBot(g), GenericRobot(*g) {
            selfLog("LandmineTrackBot created with track count: " + to_string(trackCount));
        };
};
#endif