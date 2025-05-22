#ifndef COMPONENT_H
#define COMPONENT_H

#include "../vector2d.h"

#include <vector>

using namespace std;


// Use when die()
class DieComponent {
public:
    virtual void use() = 0;
};

// Use during look()
class LookComponent {
public:
    virtual vector<Vector2D> use() = 0;
};

// Use during move()
class MoveComponent {
public:
    virtual void use() = 0;
};

#endif  // COMPONENT_H
