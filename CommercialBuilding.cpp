#include "CommercialBuilding.h"
#include "Citizen.h"

CommercialBuilding::CommercialBuilding(std::unique_ptr<BuildingState> s, int capacity, int size, int numStories, BusinessType businessType): Building(capacity){

    //this->buildingState;
    this->setState(std::move(s));

    this->size = size;
    this->numStories = numStories;
    this->businessType = businessType;

}

CommercialBuilding::CommercialBuilding(int capacity, int size, int numStories, BusinessType businessType): Building(capacity){

    this->size = size;
    this->numStories = numStories;
    this->businessType = businessType;

    //this->buildingState = nullptr;
    this->setState(std::make_unique<UnderConstruction>());

}

float CommercialBuilding::getCost(){

    return 50000;

}

void CommercialBuilding::provideService(){

    if(businessType == LUXURY){

        std::cout << "Building sells luxury items" << std::endl;

    } else if(businessType == FOOD){

        std::cout << "Building is selling food" << std::endl;

    } else if(businessType == GENERAL){

        std::cout << "Building is selling general items" << std::endl;

    }

}

int CommercialBuilding::getSize(){

    return size;

}

int CommercialBuilding::getNumStories(){

    return numStories;

}

BusinessType CommercialBuilding::getBusinessType(){

    return businessType;

}

void CommercialBuilding::addEmployees(){

    if(allCitizens.empty()){

        std::cout << "No citizens to attach." << std::endl;
        return;

    }

    int EmployeesAdded = 0;

    for(Citizen* citizen: allCitizens){

        if(EmployeesAdded >= capacity){

            break;

        }

        if(citizen->getHasJob() == false){

            this->attach(citizen);
            citizen->setJobStatus(true);
            EmployeesAdded++;

        }

    }

    ChangeData changeData = {"BuildingConstructed", 2.0f};

    notify(changeData);

}

CommercialBuilding* CommercialBuilding::clone(){
    CommercialBuilding* temp=new CommercialBuilding(this->capacity, this->size, this->numStories, this->businessType);
    return temp;
}

CommercialBuilding::~CommercialBuilding(){

    //building state deleted in Building class

}