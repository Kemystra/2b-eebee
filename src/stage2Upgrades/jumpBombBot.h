#ifndef JUMPBOMBBOT_H
#define JUMPBOMBBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpBombBot: public BombBot, public JumpBot{
    public:
        void thinkAndExecute() override;
};
#endif