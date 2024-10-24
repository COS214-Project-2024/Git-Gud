#ifndef RESIDENTIALBUILDINGFACTORY_CPP
#define RESIDENTIALBUILDINGFACTORY_CPP

#include "ResidentialBuildingFactory.h"

Building* ResidentialBuildingFactory::constructBuilding(){
    return new ResidentialBuilding();
}

#endif