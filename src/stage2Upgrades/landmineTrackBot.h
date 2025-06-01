#ifndef LANDMINETRACKBOT_H
#define LANDMINETRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LandmineTrackBot: public LandmineBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif