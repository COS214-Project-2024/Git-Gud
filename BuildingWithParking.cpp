#include "BuildingWithParking.h"

BuildingWithParking::BuildingWithParking(Building* b){
    this->building=b;
    this->building->setState(new UnderConstruction());
}

void BuildingWithParking::provideService(){
    this->building->provideService(); 
    std::cout <<" and provides parking" << std::endl;
}

float BuildingWithParking::getCost(){
    return 10000 + this->building->getCost();
}

void BuildingWithParking::setState(BuildingState* s){
    this->building->setState(s);
}

void BuildingWithParking::repairBuilding(){
    this->building->repairBuilding();
}

std::string BuildingWithParking::currentState(){
    return this->building->currentState();
}

void BuildingWithParking::simulateConstruction(){
    this->building->simulateConstruction();
}

int BuildingWithParking::getNumStories(){
    return this->building->getNumStories();
}

BusinessType BuildingWithParking::getBusinessType(){
    return this->building->getBusinessType();
}

void BuildingWithParking::addEmployees(){
    this->building->addEmployees();
}

int BuildingWithParking::getSize(){
    return this->building->getSize();
}

float BuildingWithParking::getPollutionLevel(){
    return this->building->getPollutionLevel();
}

void BuildingWithParking::addCitizens(){
    this->building->addCitizens();
}

std::list<Citizen*> BuildingWithParking::getTenants(){
    this->building->getTenants();
}

BuildingWithParking* BuildingWithParking::clone(){
    BuildingWithParking* temp=new BuildingWithParking();
    Building* b=this->building->clone();
    temp->building=b;
    return temp;
}