/**
 * @file TaxManager.h
 * @author Git-Gud
 * @brief Choose taxation method and collects tax 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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
        /// @brief List of commercial buildings
        std::list<CommercialBuilding*> commercialBuildings;
        /// @brief List of industrial buildings
        std::list<IndustrialBuilding*> industrialBuildings;
        /// @brief List of residential buildings
        std::list<ResidentialBuilding*> residentialBuildings;
        /// @brief The method of how tax is collected
        RetrieveTax* taxStrategy;
        /// @brief How much tax is collected from each building
        float currentTotalTaxRate = 20.0;
    public:
        /// @brief Destructor - Clears Lists
        ~TaxManager();

        /// @brief Collects tax depending on the taxation Strategy
        /// @return float
        float calculateTax();

        /// @brief Update the tax amount and notify citizens of new tax rates
        /// @param newRate 
        void updateTotalTaxRate(float newRate);

        /// @brief Add residential building to corresponding list
        /// @param residential 
        void addResidential(ResidentialBuilding* residential);

        /// @brief Add industrial building to corresponding list
        /// @param industrial 
        void addIndustrial(IndustrialBuilding* industrial);

        /// @brief Add commercial building to corresponding list
        /// @param commercial 
        void addCommercial(CommercialBuilding* commercial);

        /// @brief updates the taxation method
        /// @param taxMethod 
        void chooseTaxMethod(RetrieveTax* taxMethod);

};


#endif // TAXMANAGER_H