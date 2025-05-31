<<<<<<< HEAD:src/upgrades/laserBot.h
#pragma once
#include "genericRobot.h"

class LaserBot:public GenericRobot{
    public:
    using GenericRobot::GenericRobot;

    void fire(int x, int y) override;

    private:
    void fireHorizontal(int y);

    void fireVertical(int x);
};

=======
#ifndef LASERBOT_H
#define LASERRBOT_H

#include "../genericRobot.h"

class LaserBot:public GenericRobot{
};

#endif
>>>>>>> df60028676fe46b8199637aeddbbe593e35a8372:src/stage1Upgrades/laserBot.h
