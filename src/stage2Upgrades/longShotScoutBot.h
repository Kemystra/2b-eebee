#ifndef LONGSHOTSCOUTBOT_H
#define LONGSHOTSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class LongShotScoutBot: public LongShotBot, public ScoutBot{
    public:
        void thinkAndExecute() override;
};
#endif