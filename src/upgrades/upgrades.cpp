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
            return vector<Upgrade>{TrackBot, HideBot};
    }
}
