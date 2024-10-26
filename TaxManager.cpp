#include "TaxManager.h"
#include "Subject.h"

void TaxManager::updateTotalTaxRate(float newRate){

    //Citizens get notified of the change (Observer) 
    ChangeData changeData = {"TaxChange", newRate - currentTotalTaxRate}; //take change in taxrate

    notify(changeData);


    //Add rest of implementation for this function

}

