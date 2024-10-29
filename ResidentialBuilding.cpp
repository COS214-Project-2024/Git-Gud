#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding(int capacity):Building(capacity){

    //leave empty

}

ResidentialBuilding::ResidentialBuilding(BuildingState* s, int capacity): Building(capacity){

    this->buildingState = s;

}

ResidentialBuilding::~ResidentialBuilding(){

    tenants.clear();

}

void ResidentialBuilding::provideService(){

    //provide service

}

float ResidentialBuilding::getCost(){

    //get cost

}

void ResidentialBuilding::addCitizens(){

    for(int i = 0; i < this->capacity; i++){

        tenants.push_back(new Citizen);

    }

    

}

std::list<Citizen*> ResidentialBuilding::getTenants(){
    return tenants;
}