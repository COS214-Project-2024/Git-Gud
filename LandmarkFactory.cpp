#ifndef LANDMARKFACTORY_CPP
#define LANDMARKFACTORY_CPP

#include "LandmarkFactory.h"

Building* LandmarkFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new LandmarkBuilding(new UnderConstruction());
    }
    return nullptr;
}

#endif