#include "Building.h"

void Building::setState(BuildingState* s){

    if(this->buildingState != NULL){

        delete this->buildingState;

    }

    this->state = s;

}

Building::Building(){

    this->setState(new UnderConstruction);

}

