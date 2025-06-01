#ifndef HIDETHIRTYSHOTSCOUTBOT_H
#define HIDETHIRTYSHOTSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/hideThirtyShotBot.h"
class HideThirtyShotScoutBot : public HideThirtyShotBot, public ScoutBot {
public:
    HideThirtyShotScoutBot(GenericRobot* g) : HideThirtyShotBot(g), ScoutBot(g) {};
};

#endif
