#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "BuildingState.h"

class Operational : public BuildingState{

    public:

        Operational() = default;  
        ~Operational(){};

        void enterState(Building *building) override;
        void exitState(Building* building) override;

        void nextState(Building* building) override;
        std::string getCurrentState() override;

};


#endif // OPERATIONAL_H