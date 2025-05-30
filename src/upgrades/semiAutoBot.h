#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "../genericRobot.h"

class SemiAutoBot:public GenericRobot{
    public:
    int getBulletsPerShot() const override{
        return 3;
    }

     
};

//     public:
//         void fire(int x, int y) override;
// };

#endif