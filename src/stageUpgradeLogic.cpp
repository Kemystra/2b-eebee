#include "stageUpgradeLogic.h"

GenericRobot* chooseStage1Upgrade(GenericRobot* robot, Upgrade upgrade){
    vector<UpgradeTrack> possibleUpgradeTracks = robot->getPossibleUpgradeTracks();
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

}

GenericRobot* chooseUpgradeStage(GenericRobot* robot, Upgrade upgrade) {
    if (robot->getUpgrades().size() ==0) {
        return chooseStage1Upgrade(robot, upgrade);
    }
    else if (robot->getUpgrades().size() == 1) {
        return chooseStage2Upgrade(robot, upgrade);
    }
    else {
        return chooseStage3Upgrade(robot, upgrade);
    }
}