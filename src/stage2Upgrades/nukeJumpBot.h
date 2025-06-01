#ifndef NUKEJUMPBOT_H
#define NUKEJUMPBOT_H

#include "../stage1Upgrades/nukeBot.h"
#include "../stage1Upgrades/jumpBot.h"

class NukeJumpBot : public NukeBot, public JumpBot {
    public: 
        NukeJumpBot(GenericRobot* g) : GenericRobot(*g), NukeBot(g), JumpBot(g) {
            selfLog("NukeJumpBot created.");
        };
        void thinkAndExecute() override;
};
#endif