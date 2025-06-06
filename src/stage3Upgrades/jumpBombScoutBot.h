#ifndef JUMPBOMBSCOUTBOT_H
#define JUMPBOMBSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/jumpBombBot.h"
class JumpBombScoutBot : public JumpBombBot, public ScoutBot {
public:
    JumpBombScoutBot(GenericRobot* g) : GenericRobot(*g),JumpBombBot(g), ScoutBot(g),JumpBot(g),BombBot(g)  {};
    void thinkAndExecute() override;
};

#endif
