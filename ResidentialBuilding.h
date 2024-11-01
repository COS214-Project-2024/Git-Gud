#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "Building.h"
#include <list>

class ResidentialBuilding : public Building{

    private:
        std::list<Citizen*> tenants;
    public:

    //protected: Changed to accomodate factory
        ~ResidentialBuilding();

        ResidentialBuilding(int capacity);
        ResidentialBuilding(BuildingState* s, int capacity);

        virtual void provideService() override;

        virtual float getCost() override;
        void addCitizens();

        std::list<Citizen*> getTenants();

        virtual ResidentialBuilding* clone() const override;

};


#endif // RESIDENTIALBUILDING_H