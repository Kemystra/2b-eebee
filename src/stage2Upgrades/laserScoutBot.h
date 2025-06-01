#ifndef LASERSCOUTBOT_H
#define LASERSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LaserScoutBot: public LaserBot, public ScoutBot{
    public:
        void thinkAndExecute() override;
};
#endif