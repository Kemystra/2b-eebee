#ifndef JUMPLASERSCOUTBOT_H
#define JUMPLASERSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/jumpLaserBot.h"
class JumpLaserScoutBot : public JumpLaserBot, public ScoutBot {
public:
    JumpLaserScoutBot(GenericRobot* g) : GenericRobot(*g), JumpLaserBot(g), ScoutBot(g),JumpBot(g),LaserBot(g) {};
    void thinkAndExecute() override;
};

#endif
