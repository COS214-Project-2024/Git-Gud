#include "BuildingWithCoffeeshop.h"

BuildingWithCoffeeShop::BuildingWithCoffeeShop(Building* b){
    this->building=b;
    this->setState(new UnderConstruction());
    this->cost=10000;
}

void BuildingWithCoffeeShop::provideService(){
    this->building->provideService();
}

float BuildingWithCoffeeShop::getCost(){
    return this->cost+this->building->getCost();
}