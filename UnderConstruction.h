#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "BuildingState.h"

class UnderConstruction : public BuildingState{
    
    public:

        UnderConstruction() = default;  

        void enterState(Building *building) override;
        void exitState(Building* building) override;

        void nextState(Building* building) override;
        std::string getCurrentState() override;
    

};


#endif // UNDERCONSTRUCTION_H