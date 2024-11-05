#include "IndustrialBuilding.h"
#include "Citizen.h"
#include <iostream>
#include <memory>

IndustrialBuilding::IndustrialBuilding(std::unique_ptr<BuildingState> s, int capacity, int size, int numStories, Industry industryType, int pollutionLevel):Building(capacity){

    this->setState(std::move(s));

    this->size = size;
    this->numStories = numStories;
    this->industryType = industryType;
    this->pollutionLevel = pollutionLevel;

}

IndustrialBuilding::IndustrialBuilding(int capacity, int size, int numStories, Industry industryType, int pollutionLevel): Building(capacity){

    this->size = size;
    this->numStories = numStories;
    this->industryType = industryType;
    this->pollutionLevel = pollutionLevel;

    this->setState(std::make_unique<UnderConstruction>());

}

int IndustrialBuilding::getSize(){

    return size;

}

int IndustrialBuilding::getNumStories(){

    return numStories;

}

Industry IndustrialBuilding::getIndustryType(){

    return industryType;

}

float IndustrialBuilding::getPollutionLevel(){

    return pollutionLevel;

}

void IndustrialBuilding::provideService(){

    if(industryType == MANUFACTURING){

        std::cout << "Building is manufacturing items" << std::endl;

    } else if(industryType == ENERGY){

        std::cout << "Building is generating energy" << std::endl;

    } else if(industryType == TECHNOLOGY){

        std::cout << "Building is producing different technologies" << std::endl;

    }

}

float IndustrialBuilding::getCost(){

    return 50000;

}

void IndustrialBuilding::addEmployees(){

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

    ChangeData changeData = {"BuildingConstructed", 1.0f};

    notify(changeData);

}

IndustrialBuilding* IndustrialBuilding::clone(){
    IndustrialBuilding* temp=new IndustrialBuilding(this->capacity, this->size, this->numStories, this->industryType, this->pollutionLevel);
    return temp;
}

std::string IndustrialBuilding::getType(){

    return "IndustrialBuilding";

}