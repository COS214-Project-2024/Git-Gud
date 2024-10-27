#include "Dilapidated.h"
#include "Building.h"
#include "Operational.h"

void Dilapidated::enterState(Building *building){

    std::cout << "Building is Delapidated" << std::endl;

}

void Dilapidated::exitState(Building *building){

    std::cout << "Building is no longer Delapidated" << std::endl;

}

void Dilapidated::nextState(Building *building){

    building->setState(new Operational());

}