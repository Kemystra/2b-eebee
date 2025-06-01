#ifndef BOMBTRACKBOT_H
#define BOMBTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class BombTrackBot: virtual public BombBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override;
        BombTrackBot(GenericRobot* g) : BombBot(g), TrackBot(g),GenericRobot(*g) {
            selfLog("BombTrackBot created");
        };
};
#endif