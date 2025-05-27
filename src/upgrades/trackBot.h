#ifndef TRACKBOT_H
#define TRACKBOT_H

#include "../genericRobot.h"
#include <variant>
#include <memory>
class TrackBot:public GenericRobot{
    private:
        vector<GenericRobot*> trackedBots;  //  saves tracked robot pointers
    public:
        void track(Vector2D positionOfRobot); // track a robot at a given position
};

#endif