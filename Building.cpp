#include "Building.h"
#include "Operational.h"
#include "UnderConstruction.h"

void Building::setState(BuildingState* s){

    if(this->buildingState != NULL){

        delete this->buildingState;

    }

    this->state = s;

}

Building::Building(){

    this->setState(new UnderConstruction);

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