#include "BuildingWithParkingFactory.h"

Building* BuildingWithParkingFactory::upgradeBuilding(Building* b){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new BuildingWithParking(b);
    }
    return b;
}

BuildingWithParking* BuildingWithParkingFactory::cloneBuilding(){
    return dynamic_cast<BuildingWithParking*>(building)->clone();
}