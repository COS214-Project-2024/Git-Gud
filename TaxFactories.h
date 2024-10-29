#ifndef TAXFACTORIES_H
#define TAXFACTORIES_H

#include "RetrieveTax.h"

class TaxFactories : public RetrieveTax
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


#endif // TAXFACTORIES_H