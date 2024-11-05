/**
 * @file TaxResidents.h
 * @author Git-Gud
 * @brief Get tax from the citizens in residential buildings
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef TAXRESIDENTS_H
#define TAXRESIDENTS_H

#include "RetrieveTax.h"

class TaxResidents : public RetrieveTax
{
private:
    
public:
    /// @brief Collect tax from buildings (Strategy) - Tax recieved from citizens is influenced by satisfaction level
    /// @param resBuildings 
    /// @param comBuildings 
    /// @param indBuildings 
    /// @param tax 
    /// @return 
    virtual float CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax);
};


#endif // TAXRESIDENTS_H