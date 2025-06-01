#ifndef NUKESCOUTBOT_H
#define NUKESCOUTBOT_H

#include "../stage1Upgrades/nukeBot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../genericRobot.h"

class NukeScoutBot : public NukeBot, public ScoutBot {
    public: 
        NukeScoutBot(GenericRobot* g) : GenericRobot(*g), NukeBot(g), ScoutBot(g) {
            selfLog("NukeScoutBot created with scout count: " + to_string(scoutCount));
        };
        void thinkAndExecute() override;
};
#endif