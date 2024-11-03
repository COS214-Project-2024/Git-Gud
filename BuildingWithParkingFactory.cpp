#include "BuildingWithParkingFactory.h"

BuildingWithParking* BuildingWithParkingFactory::upgradeBuilding(Building* b){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        Rmanager->useResource("wood",this->wood);
        Rmanager->useResource("steel",this->steel);
        Rmanager->useResource("concrete",this->concrete);
        Rmanager->useResource("waterSupply",this->water);
        Rmanager->useResource("energySupply", this->power);
        return new BuildingWithParking(b);
    }
    return nullptr;
}

BuildingWithParking* BuildingWithParkingFactory::cloneBuilding(Building* b){
    Building* c=dynamic_cast<BuildingWithParking*>(b)->building->clone();
    return new BuildingWithParking(c);
}