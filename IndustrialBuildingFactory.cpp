#ifndef INDUSTRIALBUILDINGFACTORY_CPP
#define INDUSTRIALBUILDINGFACTORY_CPP

#include "IndustrialBuildingFactory.h"

IndustrialBuilding* IndustrialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        Rmanager->useResource("wood",this->wood);
        Rmanager->useResource("steel",this->steel);
        Rmanager->useResource("concrete",this->concrete);
        Rmanager->useResource("waterSupply",this->water);
        Rmanager->useResource("energySupply", this->power);
        return new IndustrialBuilding(std::make_unique<UnderConstruction>(), 100, 50, 4, Industry::MANUFACTURING, 1);
    }
    return nullptr;
}

IndustrialBuilding* IndustrialBuildingFactory::cloneBuilding(Building* b){
    return dynamic_cast<IndustrialBuilding*>(b)->clone();
}

#endif