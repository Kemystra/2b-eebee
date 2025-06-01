#ifndef SEMIAUTOTRACKBOT_H
#define SEMIAUTOTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class SemiAutoTrackBot: public SemiAutoBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif