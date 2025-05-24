#ifndef GENERIC_ROBOT_H
#define GENERIC_ROBOT_H

#include "abstractRobot/robot.h"
#include "abstractRobot/movingRobot.h"
#include "abstractRobot/thinkingRobot.h"
#include "abstractRobot/seeingRobot.h"
#include "abstractRobot/shootingRobot.h"

#include "vector2d.h"

#include <vector>

// Forward declaration to avoid recursive includes
// Basically Environment depends on GenericRobot, but GenericRobot ALSO depends on Environment
// Compiler complains about this
// Instead of including, we just write the declaration directly
class Environment;




class GenericRobot : public MovingRobot, public ThinkingRobot, public SeeingRobot, public ShootingRobot {
public:
    GenericRobot(Vector2D initialPosition, string name, Environment* env);

    DeadState die() override;
    void gotHit() override;
    void thinkAndExecute() override;

    string getName() const override;
    Vector2D getPosition() const override;
    vector<RobotUpgrades> getUpgrades() const override;

    // Print the map grid with robot positions and cardinal directions
    // Assumes Environment will call this and provide access to all robots
    char getSymbol() const;


protected:
    // These will have to be initialized
    string name;
    Vector2D position;

    int respawnCountLeft = 3;
    Environment* environment;

    // SeeingRobot
    vector<Vector2D> look(int x, int y) override;

    // ShootingRobot
    void fire(int x, int y) override;

    // MovingRobot
    void move(int x, int y) override;

    // Upgrade necessities
    int getBulletsPerShot() const override;
    int getMaxFiringDistance() const override;
};

#endif  // GENERIC_ROBOT_H
