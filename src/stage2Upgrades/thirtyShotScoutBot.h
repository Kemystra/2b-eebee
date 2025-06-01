#ifndef THIRTYSHOTSCOUTBOT_H
#define THIRTYSHOTSCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class ThirtyShotScoutBot: public ThirtyShotBot, public ScoutBot{
    public:
        void thinkAndExecute() override;
};
#endif