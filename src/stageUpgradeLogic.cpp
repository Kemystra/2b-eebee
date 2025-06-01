#include "stageUpgradeLogic.h"

GenericRobot* chooseStage1Upgrade(GenericRobot* robot, Upgrade upgrade){
    switch (upgrade)
    {
    case ScoutBot:
        robot->removeUpgradeTrack("Seeing");
        return new class ScoutBot(robot);
    case HideBot:
        robot->removeUpgradeTrack("Moving");
        return new class HideBot(robot);
    case JumpBot:
        robot->removeUpgradeTrack("Moving");
        return new class JumpBot(robot);
    case LongShotBot:
        robot->removeUpgradeTrack("Shooting");
        return new class LongShotBot(robot);
    case SemiAutoBot:
        robot->removeUpgradeTrack("Shooting");
        return new class SemiAutoBot(robot);
    case ThirtyShotBot:
        robot->removeUpgradeTrack("Shooting");
        return new class ThirtyShotBot(robot);
    case NukeBot:
        robot->removeUpgradeTrack("Shooting");
        return new class NukeBot(robot);
    case BombBot:
        robot->removeUpgradeTrack("Shooting");
        return new class BombBot(robot);
    case LaserBot:
        robot->removeUpgradeTrack("Shooting");
        // Replace with LaserBot later
        return new class BombBot(robot);
    case TrackBot:
        robot->removeUpgradeTrack("Seeing");
        return new class TrackBot(robot);
    }
}

GenericRobot* chooseStage2Upgrade(GenericRobot* robot, Upgrade upgrade){
    vector<Upgrade> upgrades = robot->getUpgrades();
    Upgrade currentUpgrade = upgrades[0];
    switch (currentUpgrade){
        case ScoutBot:
            if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideScoutBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpScoutBot(robot);
            }
            else if (upgrade == LongShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class LongShotScoutBot(robot);
            }
            else if (upgrade == SemiAutoBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class SemiAutoScoutBot(robot);
            }
            else if (upgrade == ThirtyShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class ThirtyShotScoutBot(robot);
            }
            else if (upgrade == NukeBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class NukeScoutBot(robot);
            }
            else if (upgrade == BombBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class BombScoutBot(robot);
            }
            else if (upgrade == LaserBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class LaserScoutBot(robot);
            }
            break;
        case HideBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class HideScoutBot(robot);
            }
            else if (upgrade == LongShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class HideLongShotBot(robot);
            }
            else if (upgrade == SemiAutoBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class HideSemiAutoBot(robot);
            }
            else if (upgrade == ThirtyShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class HideThirtyShotBot(robot);
            }
            else if (upgrade == NukeBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class NukeHideBot(robot);
            }
            else if (upgrade == BombBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class HideBombBot(robot);
            }
            else if (upgrade == LaserBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class HideLaserBot(robot);
            }
            else if (upgrade == TrackBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class HideTrackBot(robot);
            }
            break;
        case JumpBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class JumpScoutBot(robot);
            }
            else if (upgrade == LongShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class JumpLongShotBot(robot);
            }
            else if (upgrade == SemiAutoBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class JumpSemiAutoBot(robot);
            }
            else if (upgrade == ThirtyShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class JumpThirtyShotBot(robot);
            }
            else if (upgrade == NukeBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class NukeJumpBot(robot);
            }
            else if (upgrade == BombBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class JumpBombBot(robot);
            }
            else if (upgrade == LaserBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class JumpLaserBot(robot);
            }
            else if (upgrade == TrackBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class JumpTrackBot(robot);
            }
            break;
        case LongShotBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class LongShotScoutBot(robot);
            }
            else if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideLongShotBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpLongShotBot(robot);
            }
            else if (upgrade == TrackBot){
                robot->removeUpgradeTrack("Seeing");
                return new class LongshotTrackBot(robot);
            }
            break;
        case SemiAutoBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class SemiAutoScoutBot(robot);
            }
            else if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideSemiAutoBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpSemiAutoBot(robot);
            }
            else if (upgrade == TrackBot){
                robot->removeUpgradeTrack("Seeing");
                return new class SemiAutoTrackBot(robot);
            }
            break;
        case ThirtyShotBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class ThirtyShotScoutBot(robot);
            }
            else if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideThirtyShotBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpThirtyShotBot(robot);
            }
            else if (upgrade == TrackBot){
                robot->removeUpgradeTrack("Seeing");
                return new class ThirtyShotTrackBot(robot);
            }
            break;
        case NukeBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class NukeScoutBot(robot);
            }
            else if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class NukeHideBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class NukeJumpBot(robot);
            }
            else if (upgrade == TrackBot){
                robot->removeUpgradeTrack("Seeing");
                return new class NukeTrackBot(robot);
            }
            break;
        case BombBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class BombScoutBot(robot);
            }
            else if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideBombBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpBombBot(robot);
            }
            else if (upgrade == TrackBot){
                robot->removeUpgradeTrack("Seeing");
                return new class BombTrackBot(robot);
            }
            break;
        case LaserBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class LaserScoutBot(robot);
            }
            else if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideLaserBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpLaserBot(robot);
            }
            else if (upgrade == TrackBot){
                robot->removeUpgradeTrack("Seeing");
                return new class LaserTrackBot(robot);
            }
            break;
        case TrackBot:
            if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideTrackBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpTrackBot(robot);
            }
            else if (upgrade == LongShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class LongshotTrackBot(robot);
            }
            else if (upgrade == SemiAutoBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class SemiAutoTrackBot(robot);
            }
            else if (upgrade == ThirtyShotBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class ThirtyShotTrackBot(robot);
            }
            else if (upgrade == NukeBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class NukeTrackBot(robot);
            }
            else if (upgrade == BombBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class BombTrackBot(robot);
            }
            else if (upgrade == LaserBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class LaserTrackBot(robot);
            }
    }
}

GenericRobot* chooseStage3Upgrade(GenericRobot* robot, Upgrade upgrade){
    vector<Upgrade> upgrades = robot->getUpgrades();
    bool hasScout = false;
    bool hasHide = false;
    bool hasJump = false;
    bool hasLongShot = false;
    bool hasSemiAuto = false;
    bool hasThirtyShot = false;
    bool hasBomb = false;
    bool hasNuke = false;
    bool hasLaser = false;
    bool hasTrack = false;

    upgrades.push_back(upgrade);
    for (Upgrade u : upgrades) {
        if (u == ScoutBot) {
            hasScout = true;
        }
        else if (u == HideBot) {
            hasHide = true;
        }
        else if (u == JumpBot) {
            hasJump = true;
        }
        else if (u == LongShotBot) {
            hasLongShot = true;
        }
        else if (u == SemiAutoBot) {
            hasSemiAuto = true;
        }
        else if (u == ThirtyShotBot) {
            hasThirtyShot = true;
        }
        else if (u == BombBot) {
            hasBomb = true;
        }
        else if (u == LaserBot) {
            hasLaser = true;
        }
        else if (u == TrackBot) {
            hasTrack = true;
        }
        else if (u == NukeBot) {
            hasNuke = true;
        }
    }
    if (hasScout && hasHide && hasBomb){
        switch (upgrade) {
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case BombBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideBombScoutBot(robot);
    }
    else if (hasTrack && hasBomb && hasHide){
        switch (upgrade) {
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case BombBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideBombTrackBot(robot);
    }
    else if (hasHide && hasLaser && hasScout){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case LaserBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideLaserScoutBot(robot);
    }
    else if (hasHide && hasLaser && hasTrack){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case LaserBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideLaserTrackBot(robot);
    }
    else if (hasHide && hasLongShot && hasScout){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case LongShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideLongShotScoutBot(robot);
    }
    else if (hasHide && hasLongShot && hasTrack){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case LongShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideLongShotTrackBot(robot);
    }
    else if (hasHide && hasSemiAuto && hasScout){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case SemiAutoBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideSemiAutoScoutBot(robot);
    }
    else if (hasHide && hasSemiAuto && hasTrack){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case SemiAutoBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideSemiAutoTrackBot(robot);
    }
    else if (hasHide && hasThirtyShot && hasScout){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case ThirtyShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideThirtyShotScoutBot(robot);
    }
    else if (hasHide && hasThirtyShot && hasTrack){
        switch (upgrade) {
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case ThirtyShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class HideThirtyShotTrackBot(robot);
    }
    else if (hasJump && hasBomb && hasScout){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case BombBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpBombScoutBot(robot);
    }
    else if (hasJump && hasBomb && hasTrack){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case BombBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpBombTrackBot(robot);
    }

    else if (hasJump && hasLaser && hasTrack){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case LaserBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpLaserTrackBot(robot);
    }
    else if (hasJump && hasLongShot && hasScout){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case LongShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpLongShotScoutBot(robot);
    }
    else if (hasJump && hasLongShot && hasTrack){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case LongShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpLongShotTrackBot(robot);
    }
    else if (hasJump && hasSemiAuto && hasScout){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case SemiAutoBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpSemiAutoScoutBot(robot);
    }
    else if (hasJump && hasSemiAuto && hasTrack){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case SemiAutoBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpSemiAutoTrackBot(robot);
    }
    else if (hasJump && hasThirtyShot && hasScout){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case ThirtyShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpThirtyShotScoutBot(robot);
    }
    else if (hasJump && hasThirtyShot && hasTrack){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
            case ThirtyShotBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpThirtyShotTrackBot(robot);
    }
    else if (hasJump && hasScout && hasLaser){
        switch (upgrade) {
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
            case LaserBot:
                robot->removeUpgradeTrack("Shooting");
        }
        return new class JumpLaserScoutBot(robot);
    }
    else if (hasNuke && hasHide && hasScout){
        switch (upgrade) {
            case NukeBot:
                robot->removeUpgradeTrack("Shooting");
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
        }
        return new class HideNukeScoutBot(robot);
    }
    else if (hasNuke && hasHide && hasTrack){
        switch (upgrade) {
            case NukeBot:
                robot->removeUpgradeTrack("Shooting");
            case HideBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
        }
        return new class HideNukeTrackBot(robot);
    }
    else if (hasNuke && hasJump && hasScout){
        switch (upgrade) {
            case NukeBot:
                robot->removeUpgradeTrack("Shooting");
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case ScoutBot:
                robot->removeUpgradeTrack("Seeing");
        }
        return new class JumpNukeScoutBot(robot);
    }
    else if (hasNuke && hasJump && hasTrack){
        switch (upgrade) {
            case NukeBot:
                robot->removeUpgradeTrack("Shooting");
            case JumpBot:
                robot->removeUpgradeTrack("Moving");
            case TrackBot:
                robot->removeUpgradeTrack("Seeing");
        }
        return new class JumpNukeTrackBot(robot);
    }
}
GenericRobot* chooseUpgradeStage(GenericRobot* robot, Upgrade upgrade) {
    if (robot->getUpgrades().size() ==0) {
        return chooseStage1Upgrade(robot, upgrade);
    }
    else if (robot->getUpgrades().size() == 1) {
        return chooseStage2Upgrade(robot, upgrade);
    }
    else {
        return chooseStage3Upgrade(robot,upgrade);
    }
}