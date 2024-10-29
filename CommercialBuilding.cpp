#include "CommercialBuilding.h"

CommercialBuilding::CommercialBuilding(BuildingState *s, int capacity, int size, int numStores, BusinessType businessType): Building(capacity){

    this->buildingState = s;

    this->size = size;
    this->numStories = numStories;
    this->businessType = businessType;

}

CommercialBuilding::CommercialBuilding(int capacity, int size, int numStories, BusinessType businessType): Building(capacity){

    this->size = size;
    this->numStories = numStories;
    this->businessType = businessType;

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