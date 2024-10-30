#include "BuildingWithParking.h"

BuildingWithParking::BuildingWithParking(Building* b){
    this->building=b;
    this->setState(new UnderConstruction());
    this->cost=15000;
}

void BuildingWithParking::provideService(){
    this->building->provideService(); 
    std::cout <<"and provides parking" << std::endl;
}

float BuildingWithParking::getCost(){
    return this->cost + this->building->getCost();
}