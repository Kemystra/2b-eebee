#ifndef JUMPNUKESCOUTBOT_H
#define JUMPNUKESCOUTBOT_H

#include "../stage2Upgrades/nukeScoutBot.h"
#include "../stage1Upgrades/stage1Upgrades.h"
class JumpNukeScoutBot : public NukeScoutBot, public JumpBot {
    public: 
        JumpNukeScoutBot(GenericRobot* g) : GenericRobot(*g), NukeScoutBot(g), JumpBot(g) {
            selfLog("JumpNukeScoutBot created");
        };
        void thinkAndExecute() override;
};

#endif