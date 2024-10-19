#ifndef INDUSTRIALBUILDINGFACTORY_H    
#define INDUSTRIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"

class IndustrialBuildingFactory : public BuildingFactory
{
private:
    
public:
    Building* constructBuilding() override;
};


#endif // INDUSTRIALBUILDINGFACTORY_H  