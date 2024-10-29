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

private:

    int power=5;
    int water=4;
    int wood=1;
    int steel=1;
    int concrete=1;

};

#endif