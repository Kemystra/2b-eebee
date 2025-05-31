#ifndef UPGRADES_H
#define UPGRADES_H

#include <vector>
#include <string>

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

// List out all upgrades under a track
vector<Upgrade> getUpgradesUnderTrack(UpgradeTrack track);

// Get string from the enum
// Should be possible with hacky C++ macros but dear lord I aint using that
// we coouuuld ALSO use struct hacking but why tf does this language have to be hacked in the first place
// This shit so ass
string stringifyUpgrade(Upgrade upgrade);

#endif  // UPGRADES_H
