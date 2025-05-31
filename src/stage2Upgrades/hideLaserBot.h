#ifndef HIDELASERBOT_H
#define HIDELASERBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideLaserBot: public HideBot, public LaserBot{
    public:
        void thinkAndExecute() override;
};
#endif