#ifndef HIDEBOMBSCOUTBOT_H
#define HIDEBOMBSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/hideBombBot.h"
class HideBombScoutBot : public HideBombBot, public ScoutBot {
public:
    HideBombScoutBot(GenericRobot* g) : HideBombBot(g), ScoutBot(g) {};
};

#endif
