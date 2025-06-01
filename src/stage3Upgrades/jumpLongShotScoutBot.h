#ifndef JUMPLONGSHOTSCOUTBOT_H
#define JUMPLONGSHOTSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/jumpLongShotBot.h"
class JumpLongShotScoutBot : public JumpLongShotBot, public ScoutBot {
public:
    JumpLongShotScoutBot(GenericRobot* g) : GenericRobot(*g),JumpLongShotBot(g), ScoutBot(g),JumpBot(g),LongShotBot(g) {};
    void thinkAndExecute()override;
};

#endif
