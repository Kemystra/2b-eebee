#include "upgrades.h"

// Vim macro ftw!!!
string stringifyUpgrade(Upgrade upgrade) {
    switch (upgrade) {
        case HideBot:
            return "HideBot";
        case JumpBot:
            return "JumpBot";
        case LongShotBot:
            return "LongShotBot";
        case SemiAutoBot:
            return "SemiAutoBot";
        case ThirtyShotBot:
            return "ThirtyShotBot";
        case LandmineBot:
            return "LandmineBot";
        case BombBot:
            return "BombBot";
        case LaserBot:
            return "LaserBot";
        case ScoutBot:
            return "ScoutBot";
        case TrackBot:
            return "TrackBot";
    }
}

vector<Upgrade> UpgradeTrack::getUpgradesUnderTrack() const {
    return Upgrades;
};
