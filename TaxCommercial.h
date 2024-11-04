/**
 * @file TaxCommercial.h
 * @author Git-Gud
 * @brief Recieve Tax from commercial Buildings
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef TAXCOMMERCIAL_H
#define TAXCOMMERCIAL_H

#include "RetrieveTax.h"

class TaxCommercial : public RetrieveTax
{
private:
    
public:
    /// @brief Collect tax from buildings (Strategy) - Changes based on type of business
    /// @param resBuildings 
    /// @param comBuildings 
    /// @param indBuildings 
    /// @param tax 
    /// @return 
    virtual float CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax);
};


#endif // TAXCOMMERCIAL_H