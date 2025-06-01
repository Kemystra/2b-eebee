#ifndef HIDELASERTRACKBOT_H
#define HIDELASERTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/hideLaserBot.h"
class HideLaserTrackBot : public HideLaserBot, public TrackBot {
public:
    HideLaserTrackBot(GenericRobot* g) : HideLaserBot(g), TrackBot(g),GenericRobot(*g), LaserBot(g),HideBot(g) {};
    void thinkAndExecute() override;
};

#endif
