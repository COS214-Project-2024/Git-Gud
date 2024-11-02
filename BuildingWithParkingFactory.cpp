#include "BuildingWithParkingFactory.h"

BuildingWithParking* BuildingWithParkingFactory::upgradeBuilding(Building* b){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new BuildingWithParking(b);
    }
    return nullptr;
}

BuildingWithParking* BuildingWithParkingFactory::cloneBuilding(Building* b){
    Building* c=dynamic_cast<BuildingWithParking*>(b)->building->clone();
    delete b;
    return new BuildingWithParking(c);
}