#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "RetrieveTax.h"
#include "Subject.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "ResidentialBuilding.h"
#include <list>

class TaxManager : public Subject{

    private:
        std::list<CommercialBuilding*> commercialBuildings;
        std::list<IndustrialBuilding*> industrialBuildings;
        std::list<ResidentialBuilding*> residentialBuildings;
        RetrieveTax* taxStrategy;
        float currentTotalTaxRate = 20.0;
    public:
        ~TaxManager();
        float calculateTax();
        void updateTotalTaxRate(float newRate);
        void addResidential(ResidentialBuilding* residential);
        void addIndustrial(IndustrialBuilding* industrial);
        void addCommercial(CommercialBuilding* commercial);
        void chooseTaxMethod(RetrieveTax* taxMethod);

};


#endif // TAXMANAGER_H