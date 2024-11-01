#ifndef INDUSTRIALBUILDINGFACTORY_CPP
#define INDUSTRIALBUILDINGFACTORY_CPP

#include "IndustrialBuildingFactory.h"

IndustrialBuilding* IndustrialBuildingFactory::constructBuilding(){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new IndustrialBuilding(new UnderConstruction(), 100, 50, 4, Industry::MANUFACTURING, 1);
    }
    return nullptr;
}

IndustrialBuilding* IndustrialBuildingFactory::cloneBuilding(){
    return dynamic_cast<IndustrialBuilding*>(this->building)->clone();
}

#endif