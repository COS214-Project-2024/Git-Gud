#ifndef COMMERCIALBUILDINGFACTORY_CPP
#define COMMERCIALBUILDINGFACTORY_CPP

#include "CommercialBuildingFactory.h"

Building* CommercialBuildingFactory::constructBuilding(){
    return new CommercialBuilding();
}

#endif