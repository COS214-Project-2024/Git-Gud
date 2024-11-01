#ifndef INDUSTRIALBUILDINGFACTORY_H    
#define INDUSTRIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "IndustrialBuilding.h"

class IndustrialBuildingFactory : public BuildingFactory
{
private:
    
public:
    IndustrialBuilding* constructBuilding() override;
    IndustrialBuilding* cloneBuilding() override;
};


#endif // INDUSTRIALBUILDINGFACTORY_H  