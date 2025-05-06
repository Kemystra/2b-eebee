#ifndef GENERIC_ROBOT_H
#define GENERIC_ROBOT_H

#include "abstractRobot/robot.h"
#include "abstractRobot/movingRobot.h"
#include "abstractRobot/thinkingRobot.h"
#include "abstractRobot/seeingRobot.h"
#include "abstractRobot/shootingRobot.h"
#include "vector2d.h"

class GenericRobot : public MovingRobot, public ThinkingRobot, public SeeingRobot, public ShootingRobot {
protected:
    Vector2D position;

public:
    GenericRobot(Vector2D initialPosition);

    void die() override;
    void gotHit() override;
    void executeTurn() override;
};

#endif  // GENERIC_ROBOT_H
