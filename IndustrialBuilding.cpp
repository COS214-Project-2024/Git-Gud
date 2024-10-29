#include "IndustrialBuilding.h"

IndustrialBuilding::IndustrialBuilding(BuildingState *s, int capacity, int size, int numStories, Industry industryType, int pollutionLevel):Building(capacity){

    this->buildingState = s;

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