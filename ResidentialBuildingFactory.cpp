#ifndef RESIDENTIALBUILDINGFACTORY_CPP
#define RESIDENTIALBUILDINGFACTORY_CPP

#include "ResidentialBuildingFactory.h"

ResidentialBuilding* ResidentialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new ResidentialBuilding(new UnderConstruction(), 50);
    }
    return nullptr;
}

ResidentialBuilding* ResidentialBuildingFactory::cloneBuilding(){
    return dynamic_cast<ResidentialBuilding*>(this->building)->clone();
}

#endif