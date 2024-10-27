#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "BuildingState.h"

class Operational : public BuildingState{

    public:

        Operational() = default;  

        void enterState(Building *building) override;
        void exitState(Building* building) override;

        void nextState(Building* building) override;

};


#endif // OPERATIONAL_H