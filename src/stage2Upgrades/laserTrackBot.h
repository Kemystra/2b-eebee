#ifndef LASERTRACKBOT_H
#define LASERTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LaserTrackBot: public LaserBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif