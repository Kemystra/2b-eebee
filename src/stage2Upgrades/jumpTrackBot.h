#ifndef JUMPTRACKBOT_H
#define JUMPTRACKBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpTrackBot: virtual public JumpBot, virtual public TrackBot{
    public:
        void thinkAndExecute() override;
        JumpTrackBot(GenericRobot* g) : JumpBot(g), TrackBot(g), GenericRobot(*g) {
            selfLog("JumpTrackBot created with jump amount: " + to_string(jumpAmount));
        };
};
#endif