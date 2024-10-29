#include "BuildingWithCoffeeshop.h"

BuildingWithCoffeeShop::BuildingWithCoffeeShop(Building* b){
    this->building=b;
    this->state=new UnderConstruction();
    this->cost=10000;
}

void BuildingWithCoffeeShop::provideService(){
    this->building->provideService();
}

int BuildingWithCoffeeShop::getCost(){
    return this->cost+this->building->getCost();
}