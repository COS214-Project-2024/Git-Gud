#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"

class BuildingFactory
{
private:

    Building* building;

    // Units of resources used to construct each building
    int wood;
    int steel;
    int concrete;
    int water;
    int power;

public:
    virtual Building* constructBuilding() = 0;
    virtual Building* cloneBuilding(Building* b) = 0;       // I have added the Building* b in the parameter since we need to know which building we are copying
};


#endif // BUILDINGFACTORY_H