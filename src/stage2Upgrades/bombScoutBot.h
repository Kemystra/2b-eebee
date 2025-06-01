#ifndef BOMBSCOUTBOT_H
#define BOMBSCOUTBOT_H
#include "../stage1Upgrades/stage1Upgrades.h"

class BombScoutBot: public BombBot, public ScoutBot {
    public:
        void thinkAndExecute()override;
};
#endif // BOMBSCOUTBOT_H