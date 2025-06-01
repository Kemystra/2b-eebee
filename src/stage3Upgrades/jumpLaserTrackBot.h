#ifndef JUMPLASERTRACKBOT_H
#define JUMPLASERTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/jumpLaserBot.h"
class JumpLaserTrackBot : public JumpLaserBot, public TrackBot {
public:
    JumpLaserTrackBot(GenericRobot* g) : GenericRobot(*g),JumpLaserBot(g), TrackBot(g),LaserBot(g),JumpBot(g) {};
    void thinkAndExecute() override;
};

#endif
