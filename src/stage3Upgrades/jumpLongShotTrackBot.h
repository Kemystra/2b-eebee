#ifndef JUMPLONGSHOTTRACKBOT_H
#define JUMPLONGSHOTTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/jumpLongShotBot.h"
class JumpLongShotTrackBot : public JumpLongShotBot, public TrackBot {
public:
    JumpLongShotTrackBot(GenericRobot* g) : JumpLongShotBot(g), TrackBot(g) {};
};

#endif
