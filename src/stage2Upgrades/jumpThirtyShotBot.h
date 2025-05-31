#ifndef JUMPTHIRTYSHOTBOT_H
#define JUMPTHIRTYSHOTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpThirtyShotBot: public JumpBot, public ThirtyShotBot{
    public:
        void thinkAndExecute() override;
};
#endif