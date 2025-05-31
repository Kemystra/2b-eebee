#ifndef JUMPSEMIAUTOBOT_H
#define JUMPSEMIAUTOBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpSemiAutoBot: public JumpBot, public SemiAutoBot{
    public:
        void thinkAndExecute() override;
};
#endif