#include "BuildingWithCoffeeShopFactory.h"

BuildingWithCoffeeShop* BuildingWithCoffeeShopFactory::upgradeBuilding(Building* b){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new BuildingWithCoffeeShop(b);
    }
    return nullptr;
}

BuildingWithCoffeeShop* BuildingWithCoffeeShopFactory::cloneBuilding(){
    return dynamic_cast<BuildingWithCoffeeShop*>(building)->clone();
}


