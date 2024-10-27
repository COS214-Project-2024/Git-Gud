#ifndef DELAPIDATED_H
#define DELAPIDATED_H

#include "BuildingState.h"

class Delapidated : public BuildingState{

    public:

        Delapidated() = default;  

        void enterState(Building *building) override;
        void exitState(Building* building) override;

        void nextState(Building* building) override;

};


#endif // DELAPIDATED_H