#ifndef NUKEBOT_H
#define NUKEBOT_H

#include "../genericRobot.h"
#include "../environment.h"
class NukeBot:virtual public GenericRobot{
    public:
        NukeBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("NukeBot created");
        };
        void nuke();
        void thinkAndExecute() override;
    protected: 
        int nukeCount = 1;
};

#endif