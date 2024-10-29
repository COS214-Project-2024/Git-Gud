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

    //allows thread to run concurrently and seperately from the rest
    std::thread(&Building::simulateConstruction, this).detach();

}

std::string Building::currentState(){

    return buildingState->getCurrentState();

}

void Building::repairBuilding(){

    if(this->currentState() == "UnderConstruction"){

        std::cout << "Cannot repair building Under Construction" << std::endl;

    } else if(this->currentState() == "Dilapidated"){

        this->setState(new Operational);

    } else{

        std::cout << "Building does not need a repair" << std::endl;

    }
    
}

void Building::simulateConstruction(){

    //Simulates 30 second waiting period for building construction
    std::this_thread::sleep_for(std::chrono::seconds(30));
    setState(new Operational());

}