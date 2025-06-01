#ifndef HIDESEMIAUTOSCOUTBOT_H
#define HIDESEMIAUTOSCOUTBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/scoutBot.h"
#include "../stage2Upgrades/hideSemiAutoBot.h"
class HideSemiAutoScoutBot : public HideSemiAutoBot, public ScoutBot {
public:
    HideSemiAutoScoutBot(GenericRobot* g) : GenericRobot(*g),HideSemiAutoBot(g), ScoutBot(g),HideBot(g), SemiAutoBot(g) {};
    void thinkAndExecute() override;
};

#endif
