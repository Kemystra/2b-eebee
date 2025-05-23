#ifndef GENERIC_ROBOT_H
#define GENERIC_ROBOT_H

#include "abstractRobot/robot.h"
#include "abstractRobot/movingRobot.h"
#include "abstractRobot/thinkingRobot.h"
#include "abstractRobot/seeingRobot.h"
#include "abstractRobot/shootingRobot.h"

#include "vector2d.h"
#include "environment.h"

#include <vector>


enum RobotUpgrades {
};

class GenericRobot : public MovingRobot, public ThinkingRobot, public SeeingRobot, public ShootingRobot {
public:
    GenericRobot(Vector2D initialPosition, string name, Environment* env);

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

    int respawnCountLeft = 3;
    vector<RobotUpgrades> upgrades = {};

    // The current environment this robot is in
    Environment* environment;

    // SeeingRobot
    vector<Vector2D> look(int x, int y) override;

    // ThinkingRobot
    void think() override;

    // ShootingRobot
    void fire(int x, int y) override;

    // MovingRobot
    void move(int x, int y) override;

    friend bool Environment::isRobotHere(Vector2D positionToCheck) const;
};

#endif  // GENERIC_ROBOT_H
