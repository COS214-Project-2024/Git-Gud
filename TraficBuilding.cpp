#include "TraficBuilding.h"
#include <iostream>

TraficBuilding::TraficBuilding(BuildingState *s){

    this->setState(s);

}

void TraficBuilding::provideService(){

    //provide service

}

float TraficBuilding::getCost(){

    //return cost

}

TraficBuilding* TraficBuilding::clone(){
    TraficBuilding* temp=new TraficBuilding();
    return temp;
}