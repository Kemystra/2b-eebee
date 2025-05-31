#ifndef HIDEBOMBBOT_H
#define HIDEBOMBBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideBombBot: public BombBot, public HideBot{
    public:
        void thinkAndExecute() override;
};
#endif