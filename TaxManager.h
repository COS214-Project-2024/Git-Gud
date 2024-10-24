#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "RetrieveTax.h"
#include "Subject.h"

class TaxManager : public Subject{

    private:
        RetrieveTax* taxStrategy;
        float currentTotalTaxRate;
    public:
        float calculateTax();
        void updateTotalTaxRate(float newRate);

};


#endif // TAXMANAGER_H