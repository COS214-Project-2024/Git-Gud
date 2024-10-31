#include "BuildingWithCoffeeshop.h"

BuildingWithCoffeeShop::BuildingWithCoffeeShop(Building* b){
    this->building=b;
    this->building->setState(new UnderConstruction());
}

void BuildingWithCoffeeShop::provideService(){
    this->building->provideService();
    std::cout << " and serves coffee" << std::endl;
}

float BuildingWithCoffeeShop::getCost(){
    return 5000+this->building->getCost();
}

void BuildingWithCoffeeShop::setState(BuildingState* s){
    this->building->setState(s);
}

void BuildingWithCoffeeShop::repairBuilding(){
    this->building->repairBuilding();
}

std::string BuildingWithCoffeeShop::currentState(){
    return this->building->currentState();
}
void BuildingWithCoffeeShop::simulateConstruction(){
    this->building->simulateConstruction();
}

BuildingWithCoffeeShop* BuildingWithCoffeeShop::clone(){
    BuildingWithCoffeeShop* b=new BuildingWithCoffeeShop();
    Building* temp=this->building->clone();
    b->building=temp;
    return b;
}