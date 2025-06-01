#ifndef JUMPLONGSHOTTRACKBOT_H
#define JUMPLONGSHOTTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/jumpLongShotBot.h"
class JumpLongShotTrackBot : public JumpLongShotBot, public TrackBot {
public:
    JumpLongShotTrackBot(GenericRobot* g) : GenericRobot(*g),JumpLongShotBot(g), TrackBot(g),JumpBot(g),LongShotBot(g) {};
    void thinkAndExecute() override;
};

#endif
