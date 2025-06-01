#ifndef JUMPSEMIAUTOSCOUTBOT_H
#define JUMPSEMIAUTOSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/jumpSemiAutoBot.h"
class JumpSemiAutoScoutBot : public JumpSemiAutoBot, public ScoutBot {
public:
    JumpSemiAutoScoutBot(GenericRobot* g) : JumpSemiAutoBot(g), ScoutBot(g) {};
};

#endif
