#include "Dilapidated.h"

void Delapidated::enterState(Building *building){

    std::cout << "Building is Delapidated" << std::endl;

}

void Delapidated::exitState(Building *building){

    std::cout << "Building is no longer Delapidated" << std::endl;

}

void Delapidated::nextState(Building *building){

    building->changeState(new Operational());

}