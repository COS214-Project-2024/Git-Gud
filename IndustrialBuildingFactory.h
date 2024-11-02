#ifndef INDUSTRIALBUILDINGFACTORY_H    
#define INDUSTRIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "IndustrialBuilding.h"

class IndustrialBuildingFactory : public BuildingFactory
{
private:
    
public:

    IndustrialBuildingFactory() : BuildingFactory(){};

    IndustrialBuilding* constructBuilding() override;
    IndustrialBuilding* cloneBuilding(Building* b) override;

private:

    int power=5;
    int water=4;
    int wood=8;
    int steel=10;
    int concrete=5;

};


#endif // INDUSTRIALBUILDINGFACTORY_H  