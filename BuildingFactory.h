#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"
#include "ResourceManager.h"

class BuildingFactory
{
protected:

    ResourceManager* Rmanager;

    Building* building;

    // Units of resources used to construct each building
    int wood;
    int steel;
    int concrete;
    int water;
    int power;

public:
    virtual Building* constructBuilding() = 0;
    virtual Building* cloneBuilding() = 0;       // I have added the Building* b in the parameter since we need to know which building we are copying
};


#endif // BUILDINGFACTORY_H