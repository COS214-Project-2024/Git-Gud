#ifndef COMMERCIALBUILDINGFACTORY_CPP
#define COMMERCIALBUILDINGFACTORY_CPP

#include "CommercialBuildingFactory.h"

CommercialBuilding* CommercialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        std::cout << "Constructing" << std::endl;
        return new CommercialBuilding(std::make_unique<UnderConstruction>(), 50, 50, 3, BusinessType::GENERAL);
    }
    return nullptr;
}

CommercialBuilding* CommercialBuildingFactory::cloneBuilding(Building* b){
        return dynamic_cast<CommercialBuilding*>(b)->clone();
}

#endif