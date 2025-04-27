#ifndef ROBOT_H 
#define ROBOT_H

struct Position {
    int x;
    int y;
};

class Robot {
private:
    Position position;
public:
    void gotHit();
    void die();
    void executeTurn();
};

#endif // !ROBOT_H
