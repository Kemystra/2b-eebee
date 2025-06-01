#ifndef HIDEBOMBTRACKBOT_H
#define HIDEBOMBTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/hideBombBot.h"
class HideBombTrackBot : public HideBombBot, public TrackBot {
public:
    HideBombTrackBot(GenericRobot* g) : HideBombBot(g), TrackBot(g) {};
};

#endif
