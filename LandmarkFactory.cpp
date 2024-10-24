#ifndef LANDMARKFACTORY_CPP
#define LANDMARKFACTORY_CPP

#include "LandmarkFactory.h"

Building* LandmarkFactory::constructBuilding(){
    return new LandmarkBuilding();
}

#endif