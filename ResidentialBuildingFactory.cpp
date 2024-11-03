#ifndef RESIDENTIALBUILDINGFACTORY_CPP
#define RESIDENTIALBUILDINGFACTORY_CPP

#include "ResidentialBuildingFactory.h"

ResidentialBuilding* ResidentialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new ResidentialBuilding(std::make_unique<UnderConstruction>(), 50);
    }
    return nullptr;
}

ResidentialBuilding* ResidentialBuildingFactory::cloneBuilding(Building* b){
    return dynamic_cast<ResidentialBuilding*>(b)->clone();
}

#endif