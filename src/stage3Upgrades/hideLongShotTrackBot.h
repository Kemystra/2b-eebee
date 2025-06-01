#ifndef HIDELONGSHOTTRACKBOT_H
#define HIDELONGSHOTTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/hideLongShotBot.h"
class HideLongShotTrackBot : public HideLongShotBot, public TrackBot {
public:
    HideLongShotTrackBot(GenericRobot* g) : HideLongShotBot(g), TrackBot(g) {};
};

#endif
