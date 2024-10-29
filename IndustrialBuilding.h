#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "Building.h"
#include "Subject.h"

enum Industry {MANUFACTURING, ENERGY, TECHNOLOGY};

class IndustrialBuilding : public Building{
    
    private:
        int size;
        int numStories;
        Industry industryType;
        float pollutionLevel;
        
    public:
        int getSize();
        int getNumStories();
        Industry getIndustryType();
        float getPollutionLevel();

    protected:
        IndustrialBuilding(int capacity, int size, int numStories, Industry industryType, int pollutionLevel);
        IndustrialBuilding(BuildingState* s, int capacity, int size, int numStories, Industry industryType, int pollutionLevel);

        virtual void provideService() override;
        virtual float getCost() override;

};


#endif // INDUSTRIALBUILDING_H