#include "BuildingWithCoffeeShopFactory.h"

Building* BuildingWithCoffeeShopFactory::upgradeBuilding(Building* b){
    return (new BuildingWithCoffeeShop(b));
}