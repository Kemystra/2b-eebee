#ifndef JUMPLASERBOT_H
#define JUMPLASERBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpLaserBot: public JumpBot, public LaserBot{
    public:
        void thinkAndExecute() override;
};
#endif