#ifndef HIDETHIRTYSHOTBOT_H
#define HIDETHIRTYSHOTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideThirtyShotBot: public HideBot, public ThirtyShotBot{
    public:
        void thinkAndExecute() override;
};
#endif