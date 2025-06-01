#ifndef JUMPNUKETRACKBOT_H
#define JUMPNUKETRACKBOT_H

#include "../stage2Upgrades/nukeTrackBot.h"
#include "../stage1Upgrades/stage1Upgrades.h"

class JumpNukeTrackBot : public NukeTrackBot, public JumpBot {
    public: 
        JumpNukeTrackBot(GenericRobot* g) : GenericRobot(*g), NukeTrackBot(g), JumpBot(g) {
            selfLog("JumpNukeTrackBot created");
        };
        void thinkAndExecute() override;
};

#endif // JUMPNUKETRACKBOT_H