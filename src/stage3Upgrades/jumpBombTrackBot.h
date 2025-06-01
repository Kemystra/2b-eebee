#ifndef JUMPBOMBTRACKBOT_H
#define JUMPBOMBTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/jumpBombBot.h"
class JumpBombTrackBot : public JumpBombBot, public TrackBot {
public:
    JumpBombTrackBot(GenericRobot* g) : GenericRobot(*g),JumpBombBot(g), TrackBot(g),JumpBot(g),BombBot(g) {};
    void thinkAndExecute() override;
};

#endif
