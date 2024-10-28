#include "Citizen.h"

SatisfactionLevel* Citizen::getSatisfactionLevel(){
    return satisfactionLevel;
}

void Citizen::setSatisfactionLevel(SatisfactionLevel* satisfactionLevel){
    this->satisfactionLevel = satisfactionLevel;
}