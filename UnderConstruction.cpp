#include "UnderConstruction.h"
#include "Operational.h"
#include "Building.h"
#include <iostream>

void UnderConstruction::enterState(Building *building){

    std::cout << "Building is under construction" << std::endl;

}

void UnderConstruction::exitState(Building *building){

    std::cout << "Construction completed" << std::endl;

}

void UnderConstruction::nextState(Building *building){

    building->setState(new Operational());

}

std::string UnderConstruction::getCurrentState(){

    return "UnderConstruction";

}