#include "Landmark.h"
#include "GameEnvironment.h"

LandmarkBuilding::LandmarkBuilding(int capacity):Building(capacity){

    for(Citizen* citizen : allCitizens){

        attach(citizen);

    }

    if(!allCitizens.empty()){

        ChangeData changeData = {"BuildingConstructed", 4.0f};

        notify(changeData);

    }

}

LandmarkBuilding::LandmarkBuilding(BuildingState *s, int capacity): Building(capacity){

    this->buildingState = s;

}

void LandmarkBuilding::provideService(){

    std::cout << "Landmark is providing entertainment to citizens" << std::endl;

}

float LandmarkBuilding::getCost(){

    return 75000;
    
}