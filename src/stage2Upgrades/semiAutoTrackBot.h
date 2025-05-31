#ifndef SEMIAUTOTRACKBOT_H
#define SEMIAUTOTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class SemiAutoTrackBot: virtual public SemiAutoBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override;
        SemiAutoTrackBot(GenericRobot* g) : SemiAutoBot(g), TrackBot(g), GenericRobot(*g) {
            selfLog("SemiAutoTrackBot created with track count: " + to_string(trackCount));
        };
};
#endif