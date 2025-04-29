#ifndef GENERIC_ROBOT_H
#define GENERIC_ROBOT_H

#include "abstractRobot/robot.h"
#include "abstractRobot/movingRobot.h"
#include "abstractRobot/thinkingRobot.h"
#include "abstractRobot/seeingRobot.h"
#include "abstractRobot/shootingRobot.h"

class GenericRobot : public MovingRobot, public ThinkingRobot, public SeeingRobot, public ShootingRobot {

};

#endif  // GENERIC_ROBOT_H
