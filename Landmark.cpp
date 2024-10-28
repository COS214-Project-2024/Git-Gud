#include "Landmark.h"
#include "GameEnvironment.h"

LandmarkBuilding::LandmarkBuilding(int capacity):Building(capacity){

    //add citizens to obersverlist

}

LandmarkBuilding::LandmarkBuilding(BuildingState *s, int capacity): Building(capacity){

    this->buildingState = s;

}

void LandmarkBuilding::provideService(){

    std::cout << "Landmark is providing entertainment to citizens" << std::endl;

}

float LandmarkBuilding::getCost(){

    //return cost
    
}