#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "Building.h"
#include <list>

class ResidentialBuilding : public Building{

    private:
        std::list<Citizen*> tenants;
    public:

    protected:
        ResidentialBuilding();

    ResidentialBuilding(BuildingState* s);

    virtual void provideService();

    virtual int getCost();

};


#endif // RESIDENTIALBUILDING_H