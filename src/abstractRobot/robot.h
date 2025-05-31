#ifndef ROBOT_H 
#define ROBOT_H

#include <vector>
#include <string.h>

#include "../vector2d.h"

using namespace std;


class Robot {
public:
    virtual void die() = 0;

    virtual string getName() const = 0;
    virtual char getSymbol() const = 0;
    virtual Vector2D getPosition() const = 0;
};

#endif // !ROBOT_H
