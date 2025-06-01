#ifndef HIDELASERSCOUTBOT_H
#define HIDELASERSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/hideLaserBot.h"
class HideLaserScoutBot : public HideLaserBot, public ScoutBot {
public:
    HideLaserScoutBot(GenericRobot* g) : HideLaserBot(g), ScoutBot(g),HideBot(g), LaserBot(g),GenericRobot(*g){};
    void thinkAndExecute() override;
};

#endif
