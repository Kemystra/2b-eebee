#ifndef BOMBTRACKBOT_H
#define BOMBTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class BombTrackBot: public BombBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif