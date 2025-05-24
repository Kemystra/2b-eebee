#ifndef RADARBOT_H
#define RADARBOT_H

#include "../genericRobot.h"

class RadarBot:public GenericRobot{
    public:
        vector<Vector2D> look(int x, int y) override;
};

#endif