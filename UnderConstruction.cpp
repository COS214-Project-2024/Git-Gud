#include "UnderConstruction.h"
#include "Operational.h"
#include <iostream>

void UnderConstruction::enterState(Building *building){

    std::cout << "Building is under construction" << std::endl;

}

void UnderConstruction::exitState(Building *building){

    std::cout << "Construction completed" << std::endl;

}

void UnderConstruction::nextState(Building *building){

    building->changeState(new Operational());

}