#ifndef HIDEBOT_H
#define HIDEBOT_H

#include "../genericRobot.h"

class HideBot:public GenericRobot{
    public:
        void hide();
    protected:
        int hideAmount = 3; // Number of times the bot can hide
        bool isHidden = false; // Whether the bot is currently hidden
};



#endif