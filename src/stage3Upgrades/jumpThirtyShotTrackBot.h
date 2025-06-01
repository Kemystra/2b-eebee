#ifndef JUMPTHIRTYSHOTTRACKBOT_H
#define JUMPTHIRTYSHOTTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/jumpThirtyShotBot.h"
class JumpThirtyShotTrackBot : public JumpThirtyShotBot, public TrackBot {
public:
    JumpThirtyShotTrackBot(GenericRobot* g) : JumpThirtyShotBot(g), TrackBot(g) {};
};

#endif
