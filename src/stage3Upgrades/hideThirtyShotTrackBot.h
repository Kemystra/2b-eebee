#ifndef HIDETHIRTYSHOTTRACKBOT_H
#define HIDETHIRTYSHOTTRACKBOT_H

#include "../genericRobot.h"
#include "../stage1Upgrades/trackBot.h"
#include "../stage2Upgrades/hideThirtyShotBot.h"
class HideThirtyShotTrackBot : public HideThirtyShotBot, public TrackBot {
public:
    HideThirtyShotTrackBot(GenericRobot* g) : GenericRobot(*g),HideThirtyShotBot(g), TrackBot(g), HideBot(g), ThirtyShotBot(g) {};
    void thinkAndExecute() override;
};

#endif
