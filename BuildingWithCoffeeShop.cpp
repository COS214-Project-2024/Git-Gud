#include "BuildingWithCoffeeshop.h"

BuildingWithCoffeeShop::BuildingWithCoffeeShop(Building* b, int cap) : Decorator(b, cap){
    this->setState(new UnderConstruction());
    this->cost=10000;
}

void BuildingWithCoffeeShop::provideService(){
    this->building->provideService();
}

float BuildingWithCoffeeShop::getCost(){
    return this->cost+this->building->getCost();
}