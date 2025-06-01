#ifndef JUMPTHIRTYSHOTSCOUTBOT_H
#define JUMPTHIRTYSHOTSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/jumpThirtyShotBot.h"
class JumpThirtyShotScoutBot : public JumpThirtyShotBot, public ScoutBot {
public:
    JumpThirtyShotScoutBot(GenericRobot* g) : JumpThirtyShotBot(g), ScoutBot(g) {};
};

#endif
