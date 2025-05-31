#ifndef HIDESEMIAUTOBOT_H
#define HIDESEMIAUTOBOT_H

#include "../stage1Upgrades/stage1Upgrades.h"
class HideSemiAutoBot: virtual public HideBot, virtual public SemiAutoBot{
    public:
        void thinkAndExecute() override;
        HideSemiAutoBot(GenericRobot* g) : HideBot(g), SemiAutoBot(g), GenericRobot(*g) {
            selfLog("HideSemiAutoBot created");
        };
};
#endif