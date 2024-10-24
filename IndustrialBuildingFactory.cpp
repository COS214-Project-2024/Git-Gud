#ifndef INDUSTRIALBUILDINGFACTORY_CPP
#define INDUSTRIALBUILDINGFACTORY_CPP

#include "IndustrialBuildingFactory.h"

Building* IndustrialBuildingFactory::constructBuilding(){
    return new IndustrialBuilding();
}

#endif