#ifndef LANDMARKFACTORY_CPP
#define LANDMARKFACTORY_CPP

#include "LandmarkFactory.h"

LandmarkBuilding* LandmarkFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new LandmarkBuilding(new UnderConstruction(), 50);
    }
    return nullptr;
}

LandmarkBuilding* LandmarkFactory::cloneBuilding(){
    return dynamic_cast<LandmarkBuilding*>(this->building)->clone();
}

#endif