#ifndef JUMPTHIRTYSHOTBOT_H
#define JUMPTHIRTYSHOTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class JumpThirtyShotBot: virtual public JumpBot, virtual public ThirtyShotBot{
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        JumpThirtyShotBot(GenericRobot* g) : JumpBot(g), ThirtyShotBot(g), GenericRobot(*g) {
            selfLog("JumpThirtyShotBot created with jump amount: " + to_string(jumpAmount));
        };

};
#endif