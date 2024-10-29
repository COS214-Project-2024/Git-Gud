#ifndef TAXCOMMERCIAL_H
#define TAXCOMMERCIAL_H

#include "RetrieveTax.h"

class TaxCommercial : public RetrieveTax
{
private:
    
public:
    /// @brief Collect tax from buildings (Strategy)
    /// @param resBuildings 
    /// @param comBuildings 
    /// @param indBuildings 
    /// @param tax 
    /// @return 
    virtual float CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax);
};


#endif // TAXCOMMERCIAL_H