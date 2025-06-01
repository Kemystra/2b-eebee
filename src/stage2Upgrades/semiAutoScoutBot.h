#ifndef SEMIAUTOSCOUTBOT_H
#define SEMIAUTOSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class SemiAutoScoutBot: public SemiAutoBot, public ScoutBot{
    public:
        void thinkAndExecute() override;
};
#endif