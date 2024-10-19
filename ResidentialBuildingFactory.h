#ifndef RESIDENTIALBUILDINGFACTORY_H    
#define RESIDENTIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"

class ResidentialBuildingFactory : public BuildingFactory
{
private:
    
public:
    Building* constructBuilding() override;
};


#endif // RESIDENTIALBUILDINGFACTORY_H  