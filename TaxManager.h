#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "RetrieveTax.h"
#include "Subject.h"
#include <list>

class TaxManager : public Subject{

    private:
        std::list<Building*> buildings;
        RetrieveTax* taxStrategy;
        float currentTotalTaxRate;
    public:
        float calculateTax();
        void updateTotalTaxRate(float newRate);

};


#endif // TAXMANAGER_H