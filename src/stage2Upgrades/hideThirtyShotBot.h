#ifndef HIDETHIRTYSHOTBOT_H
#define HIDETHIRTYSHOTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideThirtyShotBot: virtual public HideBot, virtual public ThirtyShotBot{
    public:
        void thinkAndExecute() override;
        HideThirtyShotBot(GenericRobot* g) : HideBot(g), ThirtyShotBot(g), GenericRobot(*g) {
            selfLog("HideThirtyShotBot created");
        };
};
#endif