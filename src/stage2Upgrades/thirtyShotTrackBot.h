#ifndef THIRTYSHOTTRACKBOT_H
#define THIRTYSHOTTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class ThirtyShotTrackBot: virtual public ThirtyShotBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override;
        ThirtyShotTrackBot(GenericRobot* g) : ThirtyShotBot(g), TrackBot(g), GenericRobot(*g) {
            selfLog("ThirtyShotTrackBot created with track count: " + to_string(trackCount));
        };
};
#endif