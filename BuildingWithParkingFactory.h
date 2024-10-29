#ifndef BUILDINGWITHPARKINGFACTORY_H
#define BUILDINGWITHPARKINGFACTORY_H

#include "BuildingFactory.h"
#include "BuildingWithParking.h"

class BuildingWithParkingFactory : public BuildingFactory{

public:

    BuildingWithParkingFactory();

    virtual Building* upgradeBuilding(Building* b);

};

#endif