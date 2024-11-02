#include "Building.h"
#include "Operational.h"
#include "UnderConstruction.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>

void Building::setState(std::unique_ptr<BuildingState> s){

    this->buildingState = std::move(s);

}

Building::Building(){

    //this->buildingState = nullptr;

    capacity = 30;
    this->setState(std::make_unique<UnderConstruction>());

    //allows thread to run concurrently and seperately from the rest
    constructionFuture = std::async(std::launch::async, &Building::simulateConstruction, this);

}

Building::Building(int capacity){

    this->capacity = capacity;
    this->setState(std::make_unique<UnderConstruction>());

    //allows thread to run concurrently and seperately from the rest
    constructionFuture = std::async(std::launch::async, &Building::simulateConstruction, this); 
    //uses future to store future result of the outcome

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

        this->setState(std::make_unique<Operational>());

    } else{

        std::cout << "Building does not need a repair" << std::endl;

    }
    
}

void Building::simulateConstruction(){ //possible issue here: Building could be destructed during 30 second period (Fixed using async and future)

    //Simulates 30 second waiting period for building construction
    std::this_thread::sleep_for(std::chrono::seconds(5));
    setState(std::make_unique<Operational>());

}

int Building::getCapacity(){

    return capacity;

}

Building::~Building(){

    if(constructionFuture.valid()){

        constructionFuture.get(); //wait for asynchronous task to complete (from simulateConstruction())

    }

}

