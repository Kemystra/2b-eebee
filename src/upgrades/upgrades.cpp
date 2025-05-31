#include "upgrades.h"


vector<Upgrade> getUpgradesUnderTrack(UpgradeTrack track) {
    switch (track) {
        case Moving:
            return vector<Upgrade>{HideBot, JumpBot};
        
        case Shooting:
            return vector<Upgrade>{
                LongShotBot,
                SemiAutoBot,
                ThirtyShotBot,
                LandmineBot,
                BombBot,
                LaserBot
            };

        case Seeing:
            return vector<Upgrade>{TrackBot, ScoutBot};
    }
}

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

