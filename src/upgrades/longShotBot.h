#ifndef LONGSHOTBOT_H
#define LONGSHOTBOT_H

#include <cmath>
// #include "../genericRobot.h"
#include "../src/abstractRobot/shootingRobot.h"

using namespace std;

class LongShotBot : public ShootingRobot {
private:
    int maxFiringDistance; 

public:
    LongShotBot(int initialShells) {
        shellCount = initialShells;  // Assuming the base class uses shellCount
        maxFiringDistance = 3; // Set the maximum firing distance to 3
    }

    void fire(int x, int y) override {
        double distance = sqrt(x * x + y * y);

        if(distance > maxFiringDistance) {
            cout << "Target is out of range!" << endl;
            return;
        }

        if (shellCount <= 0) {
            cout << "No shells remaining!" << endl;
            return;
        }

        shellCount--;
    }

    int getMaxFiringDistance() const override {
        return maxFiringDistance;
    }

    int getBulletsPerShot() const override {
        return 1; // LongShotBot fires one bullet per shot
    }
};

#endif