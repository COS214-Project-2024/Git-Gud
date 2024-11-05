/**
 * @file RetrieveTax.h
 * @author Git-Gud
 * @brief Abstract class that collects tax
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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