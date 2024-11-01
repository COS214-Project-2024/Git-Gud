#ifndef COMMERCIALBUILDINGFACTORY_H    
#define COMMERCIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "CommercialBuilding.h"

class CommercialBuildingFactory : public BuildingFactory
{
private:
    
public:
    CommercialBuilding* constructBuilding() override;
    CommercialBuilding* cloneBuilding() override;
};


#endif // COMMERCIALBUILDINGFACTORY_H  