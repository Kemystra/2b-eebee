#ifndef STAGEUPGRADELOGIC_H
#define STAGEUPGRADELOGIC_H

#include "genericRobot.h"
#include "stage1Upgrades\stage1Upgrades.h"
#include "stage1Upgrades/upgrades.h"

GenericRobot* chooseStage1Upgrade(GenericRobot* robot,Upgrade upgrade);
GenericRobot* chooseStage2Upgrade(GenericRobot* robot,Upgrade upgrade);
GenericRobot* chooseStage3Upgrade(GenericRobot* robot,Upgrade upgrade);
GenericRobot* chooseUpgradeStage(GenericRobot* robot,Upgrade upgrade);

#endif // STAGE1UPGRADELOGIC_H