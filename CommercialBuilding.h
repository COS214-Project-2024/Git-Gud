#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"
#include <iostream>

enum BusinessType {LUXURY, FOOD, GENERAL};

class CommercialBuilding : public Building{

    private:
        int size;
        int numStories;
        BusinessType businessType;

    public:
        int getSize();
        int getNumStories();
        BusinessType getBusinessType();
        void addEmployees();

    //protected: Changed to accomodate factory
        CommercialBuilding(int capacity, int size, int numStories, BusinessType businessType);
        CommercialBuilding(BuildingState* s, int capacity, int size, int numStores, BusinessType businessType);

        virtual void provideService() override;
        virtual float getCost() override;

        virtual CommercialBuilding* clone() const override;

};


#endif // COMMERCIALBUILDING_H