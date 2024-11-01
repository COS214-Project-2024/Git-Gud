#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"
#include <iostream>

//enum BusinessType {LUXURY, FOOD, GENERAL};

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

        ~CommercialBuilding();

    //protected: Changed to accomodate factory
        CommercialBuilding(int capacity, int size, int numStories, BusinessType businessType);
        CommercialBuilding(std::unique_ptr<BuildingState> s, int capacity, int size, int numStories, BusinessType businessType);

        virtual void provideService() override;
        virtual float getCost() override;

        virtual CommercialBuilding* clone();

};


#endif // COMMERCIALBUILDING_H