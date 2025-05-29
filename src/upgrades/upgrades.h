#ifndef UPGRADES_H
#define UPGRADES_H

#include <vector>
#include <string>

using namespace std;

class UpgradeTrack{
    public:
        UpgradeTrack(string name, vector<Upgrade> upgrades)
            : name(name), Upgrades(upgrades) {};

        // List out all upgrades under a track
        vector<Upgrade> getUpgradesUnderTrack();
    protected:
        string name;  // Name of the upgrade track
        vector<Upgrade> Upgrades;
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
// enum UpgradeTrack {
//     Moving,
//     Shooting,
//     Seeing
// };




// Get string from the enum
// Should be possible with hacky C++ macros but dear lord I aint using that
// we coouuuld ALSO use struct hacking but why tf does this language have to be hacked in the first place
// This shit so ass
// string stringifyUpgrade(Upgrade upgrade);

#endif  // UPGRADES_H
