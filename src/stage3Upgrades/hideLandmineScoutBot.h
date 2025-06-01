#ifndef HIDELANDMINESCOUTBOT_H
#define HIDELANDMINESCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/hideLandmineBot.h"
class HideLandmineScoutBot : public HideLandmineBot, public ScoutBot {
public:
    HideLandmineScoutBot(GenericRobot* g) : HideLandmineBot(g), ScoutBot(g) {};
};

#endif
