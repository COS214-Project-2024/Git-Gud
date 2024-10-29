#ifndef BUILDINGWITHPARKING_H
#define BUILDINGWITHPARKING_H

#include "Decorator.h"
#include <vector>

class BuildingWithParking : public Decorator{

public:

    BuildingWithParking(Building* b, int cap);

    virtual void provideService();

    virtual float getCost();

private:

    Building* building;

    std::vector<Citizen*> workers;

};

#endif