#ifndef RESIDENTIALBUILDINGFACTORY_H    
#define RESIDENTIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "ResidentialBuilding.h"

class ResidentialBuildingFactory : public BuildingFactory
{
private:
    
public:
    ResidentialBuilding* constructBuilding() override;
    ResidentialBuilding* cloneBuilding() override;
};


#endif // RESIDENTIALBUILDINGFACTORY_H  