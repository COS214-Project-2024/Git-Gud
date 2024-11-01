#ifndef COMMERCIALBUILDINGFACTORY_CPP
#define COMMERCIALBUILDINGFACTORY_CPP

#include "CommercialBuildingFactory.h"

Building* CommercialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new CommercialBuilding(new UnderConstruction(), 50, 50, 3, BusinessType::GENERAL);
    }
    return nullptr;
}

#endif