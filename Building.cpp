#include "Building.h"

void Building::setState(BuildingState* s){
    delete this->state;
    this->state=s;
}