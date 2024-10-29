#include "BuildingWithCoffeeshop.h"

BuildingWithCoffeeShop::BuildingWithCoffeeShop(Building* b){
    this->building=b;
    this->state=new UnderConstruction();
}

void BuildingWithCoffeeShop::provideService(){
    this->building->provideService();
}