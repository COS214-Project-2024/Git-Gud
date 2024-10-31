#ifndef BUILDINGWITHPARKING_H
#define BUILDINGWITHPARKING_H

#include "Decorator.h"
#include <vector>

class BuildingWithParking : public Decorator{

public:

    BuildingWithParking(Building* b);

    BuildingWithParking();

    virtual void provideService();

    virtual float getCost();

    virtual void setState(BuildingState* s);

    virtual void repairBuilding();

    virtual std::string currentState();

    virtual void simulateConstruction();

    virtual BuildingWithParking* clone();

private:

    std::vector<Citizen*> workers;

};

#endif