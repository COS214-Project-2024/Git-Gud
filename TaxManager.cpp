#include "TaxManager.h"
#include "Subject.h"

void TaxManager::updateTotalTaxRate(float newRate){

    //Citizens get notified of the change (Observer)
    ChangeData changeData = {"TaxChange", newRate};

    notify(changeData);


    //Add rest of implementation for this function

}


void TaxManager::addResidential(ResidentialBuilding* residential){
    residentialBuildings.push_back(residential);
}
void TaxManager::addIndustrial(IndustrialBuilding* industrial){
    industrialBuildings.push_back(industrial);
}
void TaxManager::addCommercial(CommercialBuilding* commercial){
    commercialBuildings.push_back(commercial);
}

// Calls the collectTax from the strategy
float TaxManager::calculateTax(){
    return taxStrategy->CollectTax(residentialBuildings, commercialBuildings, industrialBuildings, currentTotalTaxRate);
}


