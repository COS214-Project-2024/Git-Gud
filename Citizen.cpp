#include "Citizen.h"
#include "Neutral.h"

Citizen::Citizen(){

    this->hasJob = false;
    this->satisfactionLevel = new Neutral();
    this->satisfactionLevel->satisfactionRating = 50;

}

Citizen::Citizen(bool hasJob){

    this->hasJob = hasJob;
    this->satisfactionLevel = new Neutral();
    this->satisfactionLevel->satisfactionRating = 50;

}

Citizen::~Citizen(){

    delete satisfactionLevel;

}

void Citizen::update(ChangeData changeData){

    if(changeData.changeType == "TaxChange"){

        handleTaxChange(changeData.value);

    } else if(changeData.changeType == "BuildingConstructed"){

        handleBuildingConstructed(changeData.value);

    } else if(changeData.changeType == "ServiceProvided"){ //for utilities

        handleServiceProvided(changeData.value);

    }

}

void Citizen::handleTaxChange(float changeInTaxRate){

    if(changeInTaxRate > 0){ //increase in tax

        //subtract SatisfactionLevel float by 'changeInTaxRate'
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating - changeInTaxRate;

    } else if(changeInTaxRate < 0){ //decrease in tax

        //add SatisfactionLevel float by 'changeInTaxRate'
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + -changeInTaxRate;

    }

    updateSatisfactionLevel();

}

void Citizen::handleBuildingConstructed(float BuildingFloat){

    if(BuildingFloat == 1.0f){

        //set satisfaction level (decrease float by 1)
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 2;

    } else if(BuildingFloat == 2.0f || BuildingFloat == 3.0f){

        //+0.5
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating - 0.5;

    } else if(BuildingFloat == 4.0f){

        //+2
        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating - 2;

    }

    updateSatisfactionLevel();


}

void Citizen::handleServiceProvided(float UtilityFloat){

    if(UtilityFloat == 1.0f){ //SewageSystem

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.5;

    } else if(UtilityFloat == 2.0f){ //PowerPlant

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 1;

    } else if(UtilityFloat == 3.0f){ //WaterFiltering

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.25;

    } else if(UtilityFloat == 4.0f){ //WasteManagement

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.5;

    } else if(UtilityFloat == 5.0f){ //HealthCare

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.75;

    } else if(UtilityFloat == 6.0f){ //Education

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.25;

    } else if(UtilityFloat == 7.0f){ //LawEnforcement

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.5;

    } else if(UtilityFloat == 8.0f){ //Transportation

        satisfactionLevel->satisfactionRating = satisfactionLevel->satisfactionRating + 0.25;

    } 

    updateSatisfactionLevel();

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

    if(this->satisfactionLevel != satisfactionLevel){

        float currentRating = this->satisfactionLevel->satisfactionRating;
        delete this->satisfactionLevel;
        this->satisfactionLevel = satisfactionLevel;
        this->satisfactionLevel->satisfactionRating = currentRating;

    }
    
}

void Citizen::updateSatisfactionLevel(){

    if(satisfactionLevel->satisfactionRating >= 0.0f && satisfactionLevel->satisfactionRating < 20.0f){

        setSatisfactionLevel(new VeryDissatisfied());

    } else if(satisfactionLevel->satisfactionRating >= 20.0f && satisfactionLevel->satisfactionRating < 40.0f){

        setSatisfactionLevel(new Dissatisfied());

    } else if(satisfactionLevel->satisfactionRating >= 40.0f && satisfactionLevel->satisfactionRating < 60.0f){

        setSatisfactionLevel(new Neutral());

    } else if(satisfactionLevel->satisfactionRating >= 60.0f && satisfactionLevel->satisfactionRating < 80.0f){

        setSatisfactionLevel(new Satisfied());

    } else if(satisfactionLevel->satisfactionRating >= 80.0f && satisfactionLevel->satisfactionRating <= 100.0f){

        setSatisfactionLevel(new VerySatisfied());

    } else{

        setSatisfactionLevel(new Neutral());

    }

}