#ifndef LASERTRACKBOT_H
#define LASERTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LaserTrackBot: virtual public LaserBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        LaserTrackBot(GenericRobot* g) : LaserBot(g), TrackBot(g), GenericRobot(*g) {
            selfLog("LaserTrackBot created with track count: " + to_string(trackCount));
        };
};
#endif