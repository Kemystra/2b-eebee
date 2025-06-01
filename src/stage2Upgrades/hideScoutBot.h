#ifndef HIDESCOUTBOT_H
#define HIDESCOUTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideScoutBot: public HideBot, public ScoutBot{
    public:
        void thinkAndExecute() override;
};
#endif