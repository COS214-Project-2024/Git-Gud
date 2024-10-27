#ifndef BUILDINGWITHCOFFEESHOPFACTORY_H
#define BUILDINGWITHCOFFEESHOPFACTORY_H

#include "BuildingFactory.h"
#include "BuildingWithCoffeeshop.h"

class BuildingWithCoffeeShopFactory : public BuildingFactory{

public:

    BuildingWithCoffeeShopFactory();

    virtual Building* upgradeBuilding(Building* b);

    virtual Building* cloneBuilding();

    virtual ~BuildingWithCoffeeShopFactory(){};

};

#endif