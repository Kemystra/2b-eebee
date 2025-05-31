#ifndef LANDMINESCOUTBOT_H
#define LANDMINESCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LandmineScoutBot: virtual public LandmineBot, virtual public ScoutBot{
    public:
        void thinkAndExecute() override;
        LandmineScoutBot(GenericRobot* g) : LandmineBot(g), ScoutBot(g), GenericRobot(*g) {
            selfLog("LandmineScoutBot created with scout count: " + to_string(scoutCount));
        };
};
#endif