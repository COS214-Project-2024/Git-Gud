#ifndef BUILDINGWITHCOFFEESHOP_H
#define BUILDINGWITHCOFFEESHOP_H

#include "Decorator.h"

class BuildingWithCoffeeShop : public Decorator{

public:

    // The interface that supports the upgradeBuilding operation must check if there are enough resources
    BuildingWithCoffeeShop(){
        this->state=new UnderConstruction();
    }

    virtual void provideService();

    virtual int getCost();

    int power=5;
    int water=4;
    int wood=1;
    int steel=1;
    int concrete=1;

};

#endif