#include "Operational.h"
#include "Dilapidated.h"
#include "Building.h"

void Operational::enterState(Building *building){

    std::cout << "Building is now operational" << std::endl;

}

void Operational::exitState(Building *building){

    std::cout << "Building is no longer operational" << std::endl;

}

void Operational::nextState(Building *building){

    building->setState(new Dilapidated());

}