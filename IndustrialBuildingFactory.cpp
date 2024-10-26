#ifndef INDUSTRIALBUILDINGFACTORY_CPP
#define INDUSTRIALBUILDINGFACTORY_CPP

#include "IndustrialBuildingFactory.h"

Building* IndustrialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new IndustrialBuilding(new UnderConstruction());
    }
    return nullptr;
}

#endif