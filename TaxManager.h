#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "RetrieveTax.h"

class TaxManager{

    private:
        RetrieveTax* taxStrategy;
        float currentTotalTaxRate;
    public:
        float calculateTax();
        void updateTotalTaxRate();

};


#endif // TAXMANAGER_H