#ifndef GENERIC_ROBOT_H
#define GENERIC_ROBOT_H

#include "abstractRobot/robot.h"
#include "abstractRobot/movingRobot.h"
#include "abstractRobot/thinkingRobot.h"
#include "abstractRobot/seeingRobot.h"
#include "abstractRobot/shootingRobot.h"

#include "vector2d.h"
#include "environment.h"
#include "component/component.h"

#include <vector>


class GenericRobot : public MovingRobot, public ThinkingRobot, public SeeingRobot, public ShootingRobot {
public:
    GenericRobot(Vector2D initialPosition, string name);

    void die() override;
    void gotHit() override;
    void executeTurn() override;

    string getName() const;
    Vector2D getPosition() const;

    // Print the map grid with robot positions and cardinal directions
    // Assumes Environment will call this and provide access to all robots
    char getSymbol() const;

private:
    Vector2D position;
    string name;

    vector<LookComponent*> LookComponents = {};
    vector<MoveComponent*> MoveComponents = {};
    vector<DieComponent*> DieComponents = {};

    // SeeingRobot
    vector<Vector2D> look(Vector2D center) override;

    // ThinkingRobot
    void think() override;

    // ShootingRobot
    void fire(Vector2D target) override;

    // MovingRobot
    void move(Vector2D destination) override;

    friend bool Environment::isRobotHere(Vector2D positionToCheck) const;
};

#endif  // GENERIC_ROBOT_H
