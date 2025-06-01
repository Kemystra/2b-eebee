#ifndef HIDETRACKBOT_H
#define HIDETRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideTrackBot: public HideBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif