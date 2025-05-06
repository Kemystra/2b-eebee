#ifndef GENERIC_ROBOT_H
#define GENERIC_ROBOT_H

#include "abstractRobot/robot.h"
#include "abstractRobot/movingRobot.h"
#include "abstractRobot/thinkingRobot.h"
#include "abstractRobot/seeingRobot.h"
#include "abstractRobot/shootingRobot.h"
#include "vector2d.h"
#include <vector>


class GenericRobot : public MovingRobot, public ThinkingRobot, public SeeingRobot, public ShootingRobot {
public:
    GenericRobot(Vector2D initialPosition, string name);

    void die() override;
    void gotHit() override;
    void executeTurn() override;

    string getName() const;

private:
    Vector2D position;
    int shellCount = 10;
    vector<Vector2D> seenRobotPosition = {};
    string name;

    // SeeingRobot
    vector<Vector2D> look(Vector2D center) override;

    // ThinkingRobot
    void think() override;

    // ShootingRobot
    void fire(Vector2D target) override;

    // MovingRobot
    void move(Vector2D destination) override;
};

#endif  // GENERIC_ROBOT_H
