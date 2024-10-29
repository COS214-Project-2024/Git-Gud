#include "BuildingFactory.h"

void BuildingFactory::setBuilding(Building* b){
    this->building=b;
}

BuildingFactory::~BuildingFactory(){
    delete this->building;
}