#ifndef UPGRADES_H
#define UPGRADES_H

#include <vector>

using namespace std;


enum UpgradeTrack {
    Moving,
    Shooting,
    Seeing
};

enum Upgrade {
    // Moving upgrades
    HideBot,
    JumpBot,

    // Shooting upgrades
    LongShotBot,
    SemiAutoBot,
    ThirtyShotBot,
    LandmineBot,
    BombBot,
    LaserBot,

    // Seeing upgrades
    ScoutBot,
    TrackBot
};

vector<Upgrade> getUpgradesUnderTrack(UpgradeTrack track);

#endif  // UPGRADES_H
