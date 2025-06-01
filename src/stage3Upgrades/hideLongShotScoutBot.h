#ifndef HIDELONGSHOTSCOUTBOT_H
#define HIDELONGSHOTSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/hideLongShotBot.h"
class HideLongShotScoutBot : public HideLongShotBot, public ScoutBot {
public:
    HideLongShotScoutBot(GenericRobot* g) : HideLongShotBot(g), ScoutBot(g) {};
};

#endif
