#ifndef LANDMINESCOUTBOT_H
#define LANDMINESCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LandmineScoutBot: public LandmineBot, public ScoutBot{
    public:
        void thinkAndExecute() override;
};
#endif