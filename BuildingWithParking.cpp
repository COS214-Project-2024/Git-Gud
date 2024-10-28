#include "BuildingWithParking.h"

BuildingWithParking::BuildingWithParking(Building* b){
    this->building=b;
    this->state=new UnderConstruction();
}

void BuildingWithParking::provideService(){
    this->building->provideService();
}