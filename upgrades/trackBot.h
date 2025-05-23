#ifndef TRACKBOT_H
#define TRACKBOT_H

#include "../src/genericRobot.h"
#include <variant>
class ScoutBot:public GenericRobot{
    private:
        vector<variant<string,int>> trackedBot;  //  saves tracked robot name and coordinates in form of ['robotName', x-coordinate, y-coordinate]
    public:
        void track();
};

#endif