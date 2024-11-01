#include "Building.h"
#include "Operational.h"
#include "UnderConstruction.h"
#include <thread>
#include <chrono>
#include <iostream>

void Building::setState(BuildingState* s){

    if(this->buildingState != nullptr){

        delete this->buildingState;

    }

    this->buildingState = s;

}

Building::Building(){

    capacity = 30;
    this->setState(new UnderConstruction);

    //allows thread to run concurrently and seperately from the rest
    std::thread(&Building::simulateConstruction, this).detach();

}

Building::Building(int capacity){

    this->capacity = capacity;
    this->setState(new UnderConstruction);

    //allows thread to run concurrently and seperately from the rest
    std::thread(&Building::simulateConstruction, this).detach();

}

Building::~Building(){

    if(buildingState != nullptr){

        delete buildingState;

    }

}

std::string Building::currentState(){

    if(buildingState != nullptr){

        return buildingState->getCurrentState();

    } else{

        return "State not set";

    }

}

void Building::repairBuilding(){

    if(!buildingState){

        std::cout << "Building state is uninitialized." << std::endl;
        return;
        
    }

    if(this->currentState() == "UnderConstruction"){

        std::cout << "Cannot repair building Under Construction" << std::endl;

    } else if(this->currentState() == "Dilapidated"){

        this->setState(new Operational);

    } else{

        std::cout << "Building does not need a repair" << std::endl;

    }
    
}

void Building::simulateConstruction(){ //possible issue here: Building could be destructed during 30 second period

    //Simulates 30 second waiting period for building construction
    std::this_thread::sleep_for(std::chrono::seconds(5));
    setState(new Operational());

}

