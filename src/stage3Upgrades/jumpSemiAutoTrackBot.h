#ifndef JUMPSEMIAUTOTRACKBOT_H
#define JUMPSEMIAUTOTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/jumpSemiAutoBot.h"
class JumpSemiAutoTrackBot : public JumpSemiAutoBot, public TrackBot {
public:
    JumpSemiAutoTrackBot(GenericRobot* g) : JumpSemiAutoBot(g), TrackBot(g) {};
};

#endif
