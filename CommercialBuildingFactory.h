#ifndef COMMERCIALBUILDINGFACTORY_H    
#define COMMERCIALBUILDINGFACTORY_H   

#include "BuildingFactory.h"
#include "CommercialBuilding.h"

class CommercialBuildingFactory : public BuildingFactory
{
private:
    
public:
    Building* constructBuilding() override;
    //Building* cloneBuilding() override;
};


#endif // COMMERCIALBUILDINGFACTORY_H  