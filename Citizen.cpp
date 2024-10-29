#include "Citizen.h"
#include "Neutral.h"

Citizen::Citizen(){

    this->hasJob = false;
    this->satisfactionLevel = new Neutral();

}

Citizen::Citizen(bool hasJob){

    this->hasJob = hasJob;
    this->satisfactionLevel = new Neutral();

}

Citizen::~Citizen(){

    if(satisfactionLevel != nullptr){

        delete satisfactionLevel;

    }

}

void Citizen::update(ChangeData changeData){

    if(changeData.changeType == "TaxChange"){

        handleTaxChange(changeData.value);

    } else if(changeData.changeType == "BuildingConstructed"){

        handleBuildingConstructed(changeData.value);

    }

}

void Citizen::handleTaxChange(float changeInTaxRate){

    if(changeInTaxRate > 0){ //increase in tax

        //subtract SatisfactionLevel float by 'changeInTaxRate'
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + changeInTaxRate; //changeInTaxRate is negative in this case, so use plus operator

    } else if(changeInTaxRate < 0){ //decrease in tax

        //add SatisfactionLevel float by 'changeInTaxRate'
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + changeInTaxRate;

    }

}

void Citizen::handleBuildingConstructed(float BuildingFloat){

    if(BuildingFloat == 1.0f){

        //set satisfaction level (decrease float by 1)
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating - 2;

    } else if(BuildingFloat == 2.0f || BuildingFloat == 3.0f){

        //+0.5
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.5;

    } else if(BuildingFloat == 4.0f){

        //+2
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 2;

    }


}

bool Citizen::getHasJob(){

    return hasJob;

}

void Citizen::setJobStatus(bool jobStatus){

    this->hasJob = jobStatus;

}

SatisfactionLevel* Citizen::getSatisfactionLevel(){
    return this->satisfactionLevel;
}

void Citizen::setSatisfactionLevel(SatisfactionLevel* satisfactionLevel){
    this->satisfactionLevel = satisfactionLevel;
}