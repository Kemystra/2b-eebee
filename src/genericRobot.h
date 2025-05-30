#ifndef GENERIC_ROBOT_H
#define GENERIC_ROBOT_H

#include "abstractRobot/robot.h"
#include "abstractRobot/movingRobot.h"
#include "abstractRobot/thinkingRobot.h"
#include "abstractRobot/seeingRobot.h"
#include "abstractRobot/shootingRobot.h"

#include "vector2d.h"
#include "logger.h"
#include "upgrades/upgrades.h"

#include <vector>
#include <cstdint>
#include <random>

// Forward declaration to avoid recursive includes
// Basically Environment depends on GenericRobot, but GenericRobot ALSO depends on Environment
// Compiler complains about this
// Instead of including, we just write the declaration directly
class Environment;

struct RobotParameter {
    string name;
    Vector2D position;
    char symbol;
};

// Robot status on the upgrading
enum UpgradeState {
    AvailableForUpgrade,
    UpgradeFull
};

enum Upgrade {
    HideBot,
    JumpBot,
    LongShotBot,
    SemiAutoBot,
    ThirtyShotBot,
    LandmineBot,
    BombBot,
    LaserBot,
    ScoutBot,
    TrackBot
};

class GenericRobot : public MovingRobot, public ThinkingRobot, public SeeingRobot, public ShootingRobot {
public:
    GenericRobot(
        RobotParameter robotParam,
        Environment* env,
        uint_fast64_t rngSeed,
        Logger* logger
    );

    DeadState die() override;
    void thinkAndExecute() override;
    UpgradeState chosenForUpgrade();

    string getName() const override;
    Vector2D getPosition() const override;
    const vector<Upgrade>& getPendingUpgrades() const;
    const vector<Upgrade>& getUpgrades() const;
    bool getIsDead() const;
    bool getIsVisible() const;

    // Print the map grid with robot positions and cardinal directions
    // Assumes Environment will call this and provide access to all robots
    char getSymbol() const override;


protected:
    // These will have to be initialized
    string name;
    char symbol;
    Vector2D position;
    int respawnCountLeft = 3;
    vector<int> movementRange={-1,1};
    bool isVisible = true;
    bool isDead = false;

    Environment* environment;
    Logger* logger;

    // The pseudorandom number generator, Mersenne Twister 19937 generator (64 bit)
    // I chose a random one lol
    mt19937_64 rng;
    vector<UpgradeTrack> possibleUpgradeTrack= {
        UpgradeTrack("Moving", {HideBot, JumpBot}),
        UpgradeTrack("Shooting", {LongShotBot, SemiAutoBot, ThirtyShotBot, LandmineBot, BombBot, LaserBot}),
        UpgradeTrack("Seeing", {ScoutBot, TrackBot})
    };
    // Current upgrades
    vector<Upgrade> upgrades = {};
    // What to add on the next upgrade cycle (see Environment::applyRobotUpgrades)
    vector<Upgrade> pendingUpgrades = {};

    // Probability is a number between 0 and 1, where 1 is always true and 0 is always false
    bool randomBool(double probability);

    // SeeingRobot
    vector<Vector2D> look(int x, int y) override;

    // ShootingRobot
    void fire(int x, int y) override;

    // MovingRobot
    void move(int x, int y) override;

    // Upgrade necessities
    int getBulletsPerShot() const override;
    int getMaxFiringDistance() const override;
    void setShellCount(int newShellCount);

    void selfLog(const string& msg);

    // GenericRobot uses a 'square' area to see if a robot is in shooting range
    // in LongShotBot however, it uses a different way of calculating distance (called taxicab distance)
    // These 2 way of checking is incompatible, so you have to override it
    //
    // I love Goh
    int calcDistance(Vector2D a) const;
};

#endif  // GENERIC_ROBOT_H
