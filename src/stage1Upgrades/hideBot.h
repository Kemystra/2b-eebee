#ifndef HIDEBOT_H
#define HIDEBOT_H

#include "../genericRobot.h"

class HideBot:public GenericRobot{
    public:
        void hide();
        void thinkAndExecute() override;
    protected:
        int hideAmount = 3; // Number of times the bot can hide
};



#endif