#ifndef DILAPIDATED_H
#define DILAPIDATED_H

#include "BuildingState.h"

class Dilapidated : public BuildingState{

    public:

        Dilapidated() = default;  

        void enterState(Building *building) override;
        void exitState(Building* building) override;

        void nextState(Building* building) override;
        std::string getCurrentState() override;

};


#endif // DILAPIDATED_H