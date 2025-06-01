#ifndef HIDELONGSHOTBOT_H
#define HIDELONGSHOTBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideLongShotBot: public HideBot, public LongShotBot{
    public:
        void thinkAndExecute() override;
};
#endif