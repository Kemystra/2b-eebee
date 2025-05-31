#ifndef BOMBSCOUTBOT_H
#define BOMBSCOUTBOT_H
#include "../stage1Upgrades/stage1Upgrades.h"

class BombScoutBot: virtual public BombBot, virtual public ScoutBot {
    public:
        void thinkAndExecute() override{ selfLog("Kill me please");};
        BombScoutBot(GenericRobot* g) : BombBot(g), ScoutBot(g),GenericRobot(*g) {
            selfLog("BombScoutBot created");
        };
};
#endif // BOMBSCOUTBOT_H