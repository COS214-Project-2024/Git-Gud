#include "BuildingWithCoffeeShopFactory.h"

Building* BuildingWithCoffeeShopFactory::upgradeBuilding(Building* b){
    if (Rmanager->sufficientMaterials(this->water, this->steel, this->concrete, this->wood, this->power)){
        return new BuildingWithCoffeeShop(b);
    }
    return b;
}
