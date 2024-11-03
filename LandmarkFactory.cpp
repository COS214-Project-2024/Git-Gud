#ifndef LANDMARKFACTORY_CPP
#define LANDMARKFACTORY_CPP

#include "LandmarkFactory.h"

LandmarkBuilding* LandmarkFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        Rmanager->useResource("wood",this->wood);
        Rmanager->useResource("steel",this->steel);
        Rmanager->useResource("concrete",this->concrete);
        Rmanager->useResource("waterSupply",this->water);
        Rmanager->useResource("energySupply", this->power);
        return new LandmarkBuilding(std::make_unique<UnderConstruction>(), 50);
    }
    return nullptr;
}

LandmarkBuilding* LandmarkFactory::cloneBuilding(Building* b){
    return dynamic_cast<LandmarkBuilding*>(b)->clone();
}

#endif