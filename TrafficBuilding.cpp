#include "TrafficBuilding.h"
#include <iostream>

TrafficBuilding::TrafficBuilding(BuildingState *s, int capacity, TransportType transportType): Building(capacity){

    this->buildingState = s;

    this->tType = transportType;

}

void TrafficBuilding::provideService(){

    //provide service

}

float TrafficBuilding::getCost(){

    //return cost

}