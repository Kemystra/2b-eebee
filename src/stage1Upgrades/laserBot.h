#ifndef LASER_BOT_H
#define LASER_BOT_H

#include "../genericRobot.h"

class LaserBot:virtual public GenericRobot{
    public:
    using GenericRobot::GenericRobot;

    void fire(int x, int y) override;
    LaserBot(GenericRobot* g) : GenericRobot(*g) {
        selfLog("LaserBot created");
    };

    private:
    void fireHorizontal(int y);

    void fireVertical(int x);
};

#endif  // LASER_BOT_H
