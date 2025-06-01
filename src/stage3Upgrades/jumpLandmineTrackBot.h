#ifndef JUMPLANDMINETRACKBOT_H
#define JUMPLANDMINETRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/jumpLandmineBot.h"
class JumpLandmineTrackBot : public JumpLandmineBot, public TrackBot {
public:
    JumpLandmineTrackBot(GenericRobot* g) : JumpLandmineBot(g), TrackBot(g) {};
};

#endif
