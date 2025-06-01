#ifndef HIDELANDMINETRACKBOT_H
#define HIDELANDMINETRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/hideLandmineBot.h"
class HideLandmineTrackBot : public HideLandmineBot, public TrackBot {
public:
    HideLandmineTrackBot(GenericRobot* g) : HideLandmineBot(g), TrackBot(g) {};
};

#endif
