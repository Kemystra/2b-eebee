#ifndef ROBOT_H 
#define ROBOT_H

struct Position {
    int x;
    int y;
};

class Robot {
protected:
    Position position;
public:
    virtual void gotHit() = 0;
    virtual void die() = 0;
    virtual void executeTurn() = 0;
};

#endif // !ROBOT_H
