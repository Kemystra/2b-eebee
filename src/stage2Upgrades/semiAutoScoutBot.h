#ifndef SEMIAUTOSCOUTBOT_H
#define SEMIAUTOSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class SemiAutoScoutBot: virtual public SemiAutoBot, virtual public ScoutBot{
    public:
        void thinkAndExecute() override;
        SemiAutoScoutBot(GenericRobot* g) : SemiAutoBot(g), ScoutBot(g), GenericRobot(*g) {
            selfLog("SemiAutoScoutBot created with scout count: " + to_string(scoutCount));
        };
};
#endif