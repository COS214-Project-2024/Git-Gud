#ifndef COMMERCIALBUILDINGFACTORY_CPP
#define COMMERCIALBUILDINGFACTORY_CPP

#include "CommercialBuildingFactory.h"

CommercialBuilding* CommercialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        Rmanager->useResource("wood",this->wood);
        Rmanager->useResource("steel",this->steel);
        Rmanager->useResource("concrete",this->concrete);
        Rmanager->useResource("waterSupply",this->water);
        Rmanager->useResource("energySupply", this->power);
        return new CommercialBuilding(std::make_unique<UnderConstruction>(), 50, 50, 3, BusinessType::GENERAL);
    }
    return nullptr;
}

CommercialBuilding* CommercialBuildingFactory::cloneBuilding(Building* b){
        return dynamic_cast<CommercialBuilding*>(b)->clone();
}

#endif