#ifndef SCOUTBOT_H
#define SCOUTBOT_H

#include "../genericRobot.h"

class ScoutBot:public GenericRobot{
    public:
        vector<Vector2D> look(int x, int y) override;
};

#endif