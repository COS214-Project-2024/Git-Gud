#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include <iostream>

class Building; //Forward declartion

class BuildingState{

    public: 
        virtual ~BuildingState(){};

        virtual void enterState(Building* building) = 0;
        virtual void exitState(Building* building) = 0;

        virtual void nextState(Building* building) = 0;

};


#endif // BUILDINGSTATE_H