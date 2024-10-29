#include "BuildingWithParking.h"

BuildingWithParking::BuildingWithParking(Building* b){
    this->building=b;
    this->state=new UnderConstruction();
    this->cost=15000;
}

void BuildingWithParking::provideService(){
    this->building->provideService();
}

int BuildingWithParking::getCost(){
    return this->cost + this->building->getCost();
}