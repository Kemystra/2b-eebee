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
    case LandmineBot:
        robot->removeUpgradeTrack("Shooting");
        return new class LandmineBot(robot);
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
            else if (upgrade == LandmineBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class LandmineScoutBot(robot);
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
            else if (upgrade == LandmineBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class HideLandmineBot(robot);
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
            else if (upgrade == LandmineBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class JumpLandmineBot(robot);
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
        case LandmineBot:
            if (upgrade == ScoutBot) {
                robot->removeUpgradeTrack("Seeing");
                return new class LandmineScoutBot(robot);
            }
            else if (upgrade == HideBot) {
                robot->removeUpgradeTrack("Moving");
                return new class HideLandmineBot(robot);
            }
            else if (upgrade == JumpBot) {
                robot->removeUpgradeTrack("Moving");
                return new class JumpLandmineBot(robot);
            }
            else if (upgrade == TrackBot){
                robot->removeUpgradeTrack("Seeing");
                return new class LandmineTrackBot(robot);
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
            else if (upgrade == LandmineBot) {
                robot->removeUpgradeTrack("Shooting");
                return new class LandmineTrackBot(robot);
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

GenericRobot* chooseUpgradeStage(GenericRobot* robot, Upgrade upgrade) {
    if (robot->getUpgrades().size() ==0) {
        return chooseStage1Upgrade(robot, upgrade);
    }
    else if (robot->getUpgrades().size() == 1) {
        return chooseStage2Upgrade(robot, upgrade);
    }
    else {
        return new class ScoutBot(robot); // Default case, should not happen
    }
}