#ifndef LANDMARKFACTORY_H    
#define LANDMARKFACTORY_H   

#include "BuildingFactory.h"
#include "Landmark.h"

class LandmarkFactory : public BuildingFactory
{
private:
    
public:
    Building* constructBuilding() override;
    Building* cloneBuilding(Building* b) override;
};


#endif // LANDMARKFACTORY_H  