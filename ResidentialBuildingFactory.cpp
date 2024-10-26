#ifndef RESIDENTIALBUILDINGFACTORY_CPP
#define RESIDENTIALBUILDINGFACTORY_CPP

#include "ResidentialBuildingFactory.h"

Building* ResidentialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new ResidentialBuilding(new UnderConstruction());
    }
    return nullptr;
}

#endif