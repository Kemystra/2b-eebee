#ifndef JUMPTRACKBOT_H
#define JUMPTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpTrackBot: public JumpBot, public TrackBot{
    public:
        void thinkAndExecute() override;
};
#endif