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

    virtual int getNumStories();

    virtual BusinessType getBusinessType();

    virtual void addEmployees();

    virtual int getSize();

    virtual float getPollutionLevel();

    virtual void addCitizens();

    virtual std::list<Citizen*> getTenants();

    virtual void addWorker();

    virtual BuildingWithParking* clone();

private:

    std::vector<Citizen*> workers;

};

#endif