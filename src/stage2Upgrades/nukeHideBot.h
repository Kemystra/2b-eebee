#ifndef NUKEHIDEBOT_H
#define NUKEHIDEBOT_H

#include "../stage1Upgrades/nukeBot.h"
#include "../stage1Upgrades/hideBot.h"

class NukeHideBot : public NukeBot, public HideBot {
    public: 
        NukeHideBot(GenericRobot* g) : GenericRobot(*g), NukeBot(g), HideBot(g) {
            selfLog("NukeHideBot created");
        };
        void thinkAndExecute() override;
};


#endif