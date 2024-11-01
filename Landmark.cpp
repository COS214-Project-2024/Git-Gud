#include "Landmark.h"
#include "GameEnvironment.h"
#include "Citizen.h"

LandmarkBuilding::LandmarkBuilding(int capacity):Building(capacity){

    for(Citizen* citizen : allCitizens){

        attach(citizen);

    }

    if(!allCitizens.empty()){

        ChangeData changeData = {"BuildingConstructed", 4.0f};

        notify(changeData);

    }

    this->setState(std::make_unique<UnderConstruction>());

}

LandmarkBuilding::LandmarkBuilding(std::unique_ptr<BuildingState> s, int capacity): Building(capacity){

    setState(std::move(s));

}

void LandmarkBuilding::provideService(){

    std::cout << "Landmark is providing entertainment to citizens" << std::endl;

}

float LandmarkBuilding::getCost(){

    return 75000;
    
}

LandmarkBuilding* LandmarkBuilding::clone(){
    LandmarkBuilding* temp=new LandmarkBuilding(this->capacity);
    temp->landmarkName=this->landmarkName;
    return temp;
}