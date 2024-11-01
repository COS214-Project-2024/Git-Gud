#ifndef LANDMARKFACTORY_H    
#define LANDMARKFACTORY_H   

#include "BuildingFactory.h"
#include "Landmark.h"

class LandmarkFactory : public BuildingFactory
{
private:
    
public:
    LandmarkBuilding* constructBuilding() override;
    LandmarkBuilding* cloneBuilding() override;
};


#endif // LANDMARKFACTORY_H  