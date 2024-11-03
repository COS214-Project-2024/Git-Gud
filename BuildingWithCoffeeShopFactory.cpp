#include "BuildingWithCoffeeShopFactory.h"

BuildingWithCoffeeShop* BuildingWithCoffeeShopFactory::upgradeBuilding(Building* b){
    if (b == nullptr) return nullptr;
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new BuildingWithCoffeeShop(b);
    }
    return nullptr;
}

BuildingWithCoffeeShop* BuildingWithCoffeeShopFactory::cloneBuilding(Building* b){
    Building* c=dynamic_cast<BuildingWithCoffeeShop*>(b)->building->clone();
    Building* temp=new BuildingWithCoffeeShop(c);
    return dynamic_cast<BuildingWithCoffeeShop*>(temp);
}


