#ifndef LANDMARKFACTORY_H    
#define LANDMARKFACTORY_H   

#include "BuildingFactory.h"

class LandmarkFactory : public BuildingFactory
{
private:
    
public:
    Building* constructBuilding() override;
};


#endif // LANDMARKFACTORY_H  