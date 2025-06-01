#ifndef JUMPSCOUTBOT_H
#define JUMPSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpScoutBot: public JumpBot, public ScoutBot{
    public:
        void thinkAndExecute() override;
};
#endif