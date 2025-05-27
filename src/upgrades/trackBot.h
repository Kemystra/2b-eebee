#ifndef TRACKBOT_H
#define TRACKBOT_H

#include "../genericRobot.h"
#include <variant>
#include <memory>
class TrackBot:public GenericRobot{
    protected:
        vector<GenericRobot*> trackedBots;  //  saves tracked robot pointers
        int trackCount = 3; // max number of robots to track
    public:
        void track(Vector2D positionOfRobot); // track a robot at a given position
};

#endif