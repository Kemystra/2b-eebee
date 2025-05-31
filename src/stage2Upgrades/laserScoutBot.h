#ifndef LASERSCOUTBOT_H
#define LASERSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LaserScoutBot: virtual public LaserBot, virtual public ScoutBot{
    public:
        void thinkAndExecute() override;
        LaserScoutBot(GenericRobot* g) : LaserBot(g), ScoutBot(g), GenericRobot(*g) {
            selfLog("LaserScoutBot created with scout count: " + to_string(scoutCount));
        };
};
#endif