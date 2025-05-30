#ifndef SCOUTBOT_H
#define SCOUTBOT_H

#include "../genericRobot.h"

class ScoutBot:public GenericRobot{
    public:
        ScoutBot(GenericRobot* g) : GenericRobot(*g) {
            selfLog("ScoutBot created with scout count: " + to_string(scoutCount));
        };
        vector<Vector2D> scout();
        void thinkAndExecute() override;
    protected:
        int scoutCount =3;
        bool useScout = false;
};

#endif
