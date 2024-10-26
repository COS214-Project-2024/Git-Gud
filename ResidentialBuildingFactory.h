#ifndef RESIDENTIALBUILDINGFACTORY_H    
#define RESIDENTIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "ResidentialBuilding.h"

class ResidentialBuildingFactory : public BuildingFactory
{
private:
    
public:
    Building* constructBuilding() override;
    Building* cloneBuilding(Building* b) override;
};


#endif // RESIDENTIALBUILDINGFACTORY_H  