#ifndef HIDELANDMINEBOT_H
#define HIDELANDMINEBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideLandmineBot: public HideBot, public LandmineBot{
    public:
        void thinkAndExecute() override;
};
#endif