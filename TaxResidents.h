#ifndef TAXRESIDENTS_H
#define TAXRESIDENTS_H

#include "RetrieveTax.h"

class TaxResidents : public RetrieveTax
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


#endif // TAXRESIDENTS_H