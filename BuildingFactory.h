#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"

class BuildingFactory
{
private:
    Building* building;
public:
    virtual Building* constructBuilding() = 0;
    virtual Building* cloneBuilding() = 0;
};


#endif // BUILDINGFACTORY_H