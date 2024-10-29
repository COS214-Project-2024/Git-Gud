#ifndef RETRIEVETAX_H
#define RETRIEVETAX_H

#include "Building.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include <list>

class RetrieveTax
{
private:

public:
    /// @brief Collect tax from buildings (Strategy)
    /// @param resBuildings 
    /// @param comBuildings 
    /// @param indBuildings 
    /// @param tax 
    /// @return 
    virtual float CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax) = 0;
    
};


#endif // RETRIEVETAX_H