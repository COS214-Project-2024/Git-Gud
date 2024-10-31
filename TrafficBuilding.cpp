#include "TrafficBuilding.h"
#include <iostream>

TrafficBuilding::TrafficBuilding(BuildingState *s, int capacity, float cost, TransportType transportType): Building(capacity){

    this->buildingState = s;

    this->tType = transportType;

}

void TrafficBuilding::provideService(){

    std::cout << "Transportation has been provided to neighbouring buildings.\nIncrease citizen satisfaction";
    //Call function to increase satisfaction

}

float TrafficBuilding::getCost(){
    return cost;
}