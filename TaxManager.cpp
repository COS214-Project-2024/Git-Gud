#include "TaxManager.h"
#include "Subject.h"

void TaxManager::updateTotalTaxRate(float newRate){

    //Citizens get notified of the change (Observer)
    ChangeData changeData = {"TaxChange", newRate};

    notify(changeData);


    //Add rest of implementation for this function

}

// Calls the collectTax from the strategy
float TaxManager::calculateTax(){
    return taxStrategy->CollectTax(buildings);
}
