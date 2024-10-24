#ifndef CITIZEN_H
#define CITIZEN_H

#include "SatisfactionLevel.h"

class Citizen{

    private:
        SatisfactionLevel* satisfactionLevel;
    public:
        void update();

};


#endif // CITIZEN_H