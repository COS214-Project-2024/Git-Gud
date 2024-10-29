#include "Building.h"
#include "Operational.h"
#include "UnderConstruction.h"
#include <thread>
#include <chrono>
#include <iostream>

void Building::setState(BuildingState* s){

    if(this->buildingState != NULL){

        delete this->buildingState;

    }

    this->buildingState = s;

}

Building::Building(int capacity){

    this->capacity = capacity;
    this->setState(new UnderConstruction);

}