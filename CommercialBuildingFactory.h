#ifndef COMMERCIALBUILDINGFACTORY_H    
#define COMMERCIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "CommercialBuilding.h"

class CommercialBuildingFactory : public BuildingFactory
{
private:
    int water=3;
    int power=7;
    int steel=5;
    int wood=2;
    int concrete=10;
public:

    CommercialBuildingFactory() :BuildingFactory(){};

    CommercialBuilding* constructBuilding() override;
    CommercialBuilding* cloneBuilding(Building* b) override;
};


#endif // COMMERCIALBUILDINGFACTORY_H  