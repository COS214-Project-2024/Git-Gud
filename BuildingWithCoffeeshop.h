#ifndef BUILDINGWITHCOFFEESHOP_H
#define BUILDINGWITHCOFFEESHOP_H

#include "Decorator.h"
#include <vector>

class BuildingWithCoffeeShop : public Decorator{

public:

    // The interface that supports the upgradeBuilding operation must check if there are enough resources
    BuildingWithCoffeeShop(Building* b);

    BuildingWithCoffeeShop();

    //BuildingWithCoffeeShop(const BuildingWithCoffeeShop& other);

    virtual void provideService();

    virtual float getCost();

    virtual void setState(BuildingState* s);

    virtual void repairBuilding();

    virtual std::string currentState();

    virtual void simulateConstruction();

    virtual ~BuildingWithCoffeeShop(){};

    virtual int getNumStories();

    virtual BusinessType getBusinessType();

    virtual void addEmployees();

    virtual int getSize();

    virtual float getPollutionLevel();

    virtual void addCitizens();

    virtual std::list<Citizen*> getTenants();

    virtual BuildingWithCoffeeShop* clone();

    virtual void addWorker();

};

#endif