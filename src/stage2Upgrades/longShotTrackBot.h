#ifndef LONGSHOTTRACKBOT_H
#define LONGSHOTTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LongshotTrackBot: public LongShotBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif