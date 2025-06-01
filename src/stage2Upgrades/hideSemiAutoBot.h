#ifndef HIDESEMIAUTOBOT_H
#define HIDESEMIAUTOBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideSemiAutoBot: public HideBot, public SemiAutoBot{
    public:
        void thinkAndExecute() override;
};
#endif