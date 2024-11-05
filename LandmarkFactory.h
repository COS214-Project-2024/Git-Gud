#ifndef LANDMARKFACTORY_H    
#define LANDMARKFACTORY_H   

#include "BuildingFactory.h"
#include "Landmark.h"

class LandmarkFactory : public BuildingFactory
{
private:
    
public:

    LandmarkFactory() : BuildingFactory(){};

    LandmarkBuilding* constructBuilding() override;
    LandmarkBuilding* cloneBuilding(Building* b) override;

private:

    int power=2;
    int water=1;
    int wood=0;
    int steel=3;
    int concrete=1;

};


#endif // LANDMARKFACTORY_H  