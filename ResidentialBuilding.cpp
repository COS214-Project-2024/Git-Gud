#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding(int capacity):Building(capacity){

    //leave empty

}

ResidentialBuilding::ResidentialBuilding(BuildingState* s, int capacity): Building(capacity){

    this->buildingState = s;

}

ResidentialBuilding::~ResidentialBuilding(){

    for(Citizen* tenant : tenants){

        delete tenant;

    }

    tenants.clear();

}

void ResidentialBuilding::provideService(){

    //provide service

}

float ResidentialBuilding::getCost(){

    return 25000;

}

void ResidentialBuilding::addCitizens(){

    for(int i = 0; i < this->capacity; i++){

        this->attach(new Citizen());

    }

    

}

