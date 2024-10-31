#include "BuildingWithCoffeeshop.h"

BuildingWithCoffeeShop::BuildingWithCoffeeShop(Building* b){
    this->building=b;
    this->setState(new UnderConstruction());
    this->cost=10000;
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

/*BuildingWithCoffeeShop::BuildingWithCoffeeShop(const BuildingWithCoffeeShop& other){
    // So we don't want to copy the workers vector over, since we don't necessarilly want the exact same workers to work at the new building
    // So we need assignment operators as well
    this->building=other.building; 
}*/