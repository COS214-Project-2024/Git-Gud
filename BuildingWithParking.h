#ifndef BUILDINGWITHPARKING_H
#define BUILDINGWITHPARKING_H

#include "Decorator.h"

class BuildingWithParking : public Decorator{

public:

    BuildingWithParking(Building* b);

    virtual void provideService();

    virtual int getCost();

private:

    Building* building;

};

#endif