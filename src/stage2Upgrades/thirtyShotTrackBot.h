#ifndef THIRTYSHOTTRACKBOT_H
#define THIRTYSHOTTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class ThirtyShotTrackBot: public ThirtyShotBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif