#ifndef BUILDINGWITHCOFFEESHOP_H
#define BUILDINGWITHCOFFEESHOP_H

#include "Decorator.h"
#include <vector>

class BuildingWithCoffeeShop : public Decorator{

public:

    // The interface that supports the upgradeBuilding operation must check if there are enough resources
    BuildingWithCoffeeShop(Building* b);

    virtual void provideService();

    virtual int getCost();

    virtual ~BuildingWithCoffeeShop(){};

private:

    std::vector<Citizen*> workers;

};

#endif