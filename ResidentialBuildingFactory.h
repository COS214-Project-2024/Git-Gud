#ifndef RESIDENTIALBUILDINGFACTORY_H    
#define RESIDENTIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "ResidentialBuilding.h"

class ResidentialBuildingFactory : public BuildingFactory
{
private:
    
public:

    ResidentialBuildingFactory() : BuildingFactory(){};

    ResidentialBuilding* constructBuilding() override;
    ResidentialBuilding* cloneBuilding(Building* b) override;

private:

    int power=5;
    int water=4;
    int wood=1;
    int steel=1;
    int concrete=1;

};


#endif // RESIDENTIALBUILDINGFACTORY_H  