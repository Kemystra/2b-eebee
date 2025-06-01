#include "laserBot.h"
#include "../environment.h"
#include <sstream>

using namespace std;

void LaserBot::fire(int x, int y){
    uniform_int_distribution<int> directionDist(0,1);
    int direction = directionDist(rng);

    if (direction == 0){
        selfLog("Firing horizontally lazer");
        fireHorizontal(position.y);
    }else{
        selfLog("Firing vertically lazer");
        fireVertical(position.x);
    }

    shellCount--;
}

void LaserBot::fireHorizontal(int y) {
    Vector2D gridSize = environment->getGridSize();
    
    for (int x = position.x; x >= 0; x--) {
        Vector2D target(x, y);
        if (!environment->isWithinBounds(target))
            break;
        
        GenericRobot* targetRobot = environment->getRobotAtPosition(target);
        if (targetRobot && targetRobot != this) {
            if (randomBool(0.7)) {
                targetRobot->die();

                ostringstream oss;
                selfLog("Killed " + targetRobot->getName() + " at (" + 
                       to_string(target.x) + ", " + to_string(target.y) + ")");
                environment->notifyKill(this, targetRobot);
            } else {
                selfLog("Missed " + targetRobot->getName());
            }
        }
        
        environment->drawLine(position.x, position.y, target.x, target.y);
        environment->placeFireMark(target.x, target.y);
    }
    
    for (int x = position.x + 1; x < gridSize.x; x++) {
        Vector2D target(x, y);
        if (!environment->isWithinBounds(target)) break;
        
        GenericRobot* targetRobot = environment->getRobotAtPosition(target);
        if (targetRobot && targetRobot != this) {
            if (randomBool(0.7)) {
                targetRobot->die();

                ostringstream oss;
                selfLog("Killed " + targetRobot->getName() + " at (" + 
                       to_string(target.x) + ", " + to_string(target.y) + ")");
                environment->notifyKill(this, targetRobot);
            } else {
                selfLog("Missed " + targetRobot->getName());
            }
        }
        
        environment->drawLine(position.x, position.y, target.x, target.y);
        environment->placeFireMark(target.x, target.y);
    }
    
    environment->printMap();
    environment->clearFireMarks();
    environment->clearLineMarks();
}

void LaserBot::fireVertical(int x) {
    Vector2D gridSize = environment->getGridSize();
    
   
    for (int y = position.y; y >= 0; y--) {
        Vector2D target(x, y);
        if (!environment->isWithinBounds(target)) break;
        
        GenericRobot* targetRobot = environment->getRobotAtPosition(target);
        if (targetRobot && targetRobot != this) {
            if (randomBool(0.7)) {
                targetRobot->die();

                ostringstream oss;
                selfLog("Killed " + targetRobot->getName() + " at (" + 
                       to_string(target.x) + ", " + to_string(target.y) + ")");
                environment->notifyKill(this, targetRobot);
            } else {
                selfLog("Missed " + targetRobot->getName());
            }
        }
        
        environment->drawLine(position.x, position.y, target.x, target.y);
        environment->placeFireMark(target.x, target.y);
    }
    
    for (int y = position.y + 1; y < gridSize.y; y++) {
        Vector2D target(x, y);
        if (!environment->isWithinBounds(target)) break;
        
        GenericRobot* targetRobot = environment->getRobotAtPosition(target);
        if (targetRobot && targetRobot != this) {
            if (randomBool(0.7)) {
                targetRobot->die();

                ostringstream oss;
                selfLog("Killed " + targetRobot->getName() + " at (" + 
                       to_string(target.x) + ", " + to_string(target.y) + ")");
                environment->notifyKill(this, targetRobot);
            } else {
                selfLog("Missed " + targetRobot->getName());
            }
        }
        
        environment->drawLine(position.x, position.y, target.x, target.y);
        environment->placeFireMark(target.x, target.y);
    }
    
    environment->printMap();
    environment->clearFireMarks();
    environment->clearLineMarks();
}
