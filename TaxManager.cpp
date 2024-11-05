#include "TaxManager.h"
#include "Subject.h"

TaxManager::~TaxManager(){
    residentialBuildings.clear();
    industrialBuildings.clear();
    commercialBuildings.clear();
}

void TaxManager::updateTotalTaxRate(float newRate){

    for(Citizen* citizen : allCitizens){ //add citizens to observerlist

        attach(citizen);

    }

    //Citizens get notified of the change (Observer) 
    ChangeData changeData = {"TaxChange", newRate - currentTotalTaxRate}; //take change in taxrate
    
    notify(changeData);

    currentTotalTaxRate = newRate;

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

void TaxManager::chooseTaxMethod(RetrieveTax* taxMethod){
    taxStrategy = taxMethod;
}

// Calls the collectTax from the strategy
float TaxManager::calculateTax(){
   return taxStrategy->CollectTax(residentialBuildings, commercialBuildings, industrialBuildings, currentTotalTaxRate);
}


