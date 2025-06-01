#ifndef JUMPLANDMINESCOUTBOT_H
#define JUMPLANDMINESCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/jumpLandmineBot.h"
class JumpLandmineScoutBot : public JumpLandmineBot, public ScoutBot {
public:
    JumpLandmineScoutBot(GenericRobot* g) : JumpLandmineBot(g), ScoutBot(g) {};
};

#endif
