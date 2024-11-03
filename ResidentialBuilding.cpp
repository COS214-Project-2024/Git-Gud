#include "ResidentialBuilding.h"
#include "Citizen.h"
#include "VerySatisfied.h"

ResidentialBuilding::ResidentialBuilding(int capacity):Building(capacity){

    addCitizens();

    ChangeData changeData = {"BuildingConstructed", 3.0f};
    notify(changeData);

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

    std::cout << "Provide services to residents" << std::endl;

}

float ResidentialBuilding::getCost(){

    return 25000;

}

void ResidentialBuilding::addCitizens(){

    for(int i = 0; i < this->capacity; i++){

        Citizen* newCitizen = new Citizen();
        this->addCitizenToSimulation(newCitizen);
        this->attach(newCitizen);
        this->tenants.push_back(newCitizen);

    }

}

std::list<Citizen*> ResidentialBuilding::getTenants(){
    return tenants;
}