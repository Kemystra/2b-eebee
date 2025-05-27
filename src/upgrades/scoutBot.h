#ifndef SCOUTBOT_H
#define SCOUTBOT_H

#include "../genericRobot.h"

class ScoutBot:public GenericRobot{
    public:
        vector<Vector2D> scout();
    protected:
        int scoutCount =3;
};

#endif