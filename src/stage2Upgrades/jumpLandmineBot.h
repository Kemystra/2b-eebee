#ifndef JUMPLANDMINEBOT_H
#define JUMPLANDMINEBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpLandmineBot: public JumpBot, public LandmineBot{
    public:
        void thinkAndExecute() override;
};
#endif