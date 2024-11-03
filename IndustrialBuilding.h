#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "Building.h"
#include "Subject.h"

class IndustrialBuilding : public Building{
    
    private:
        int size;
        int numStories;
        Industry industryType;
        float pollutionLevel;
        
    public:
        virtual int getSize();
        virtual int getNumStories();
        virtual Industry getIndustryType();
        virtual float getPollutionLevel();
        virtual void addEmployees();

    //protected: Changed to accomadte construction in factory
        IndustrialBuilding(int capacity, int size, int numStories, Industry industryType, int pollutionLevel);
        IndustrialBuilding(std::unique_ptr<BuildingState> s, int capacity, int size, int numStories, Industry industryType, int pollutionLevel);

        virtual void provideService() override;
        virtual float getCost() override;

        virtual IndustrialBuilding* clone();

};


#endif // INDUSTRIALBUILDING_H