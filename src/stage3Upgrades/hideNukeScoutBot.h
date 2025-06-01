#ifndef HIDENUKESCOUTBOT_H
#define HIDENUKESCOUTBOT_H

#include "../stage2Upgrades/nukeScoutBot.h"
#include "../stage1Upgrades/stage1Upgrades.h"

class HideNukeScoutBot : public NukeScoutBot, public HideBot {
    public: 
        HideNukeScoutBot(GenericRobot* g) : GenericRobot(*g), NukeScoutBot(g), HideBot(g) {
            selfLog("HideNukeScoutBot created");
        };
        void thinkAndExecute() override;
};
#endif  