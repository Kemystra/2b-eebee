#ifndef HIDESEMIAUTOTRACKBOT_H
#define HIDESEMIAUTOTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/hideSemiAutoBot.h"
class HideSemiAutoTrackBot : public HideSemiAutoBot, public TrackBot {
public:
    HideSemiAutoTrackBot(GenericRobot* g) : GenericRobot(*g),HideSemiAutoBot(g), TrackBot(g), HideBot(g),SemiAutoBot(g) {};
    void thinkAndExecute() override;
};

#endif
