#ifndef LONGSHOTTRACKBOT_H
#define LONGSHOTTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LongshotTrackBot: virtual public LongShotBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        LongshotTrackBot(GenericRobot* g) : LongShotBot(g), TrackBot(g), GenericRobot(*g) {
            selfLog("LongshotTrackBot created with track count: " + to_string(trackCount));
        };
};
#endif