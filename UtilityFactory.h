/**
 * @file UtilityFactory.h
 * @brief Abstract factory class for creating Utility objects and managing resources.
 * @version 0.1
 * @date 2024-11-01
 * 
 * @details The UtilityFactory class defines the interface for factories that create specific
 *          types of utilities. It includes helper methods for adjusting resources in the 
 *          ResourceManager, including managing budget expenditures.
 */

#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "Utility.h"
#include "ResourceManager.h"
#include <string>

class UtilityFactory {
protected:
    /**
     * @brief Helper method to adjust resource levels in the ResourceManager.
     * 
     * @param resourceType The type of resource to adjust (e.g., "waterSupply", "energySupply").
     * @param amount The amount to adjust (positive to add, negative to subtract).
     */
    void adjustResource(const std::string& resourceType, int amount) {
        ResourceManager::getInstance()->addResource(resourceType, amount);
    }

    /**
     * @brief Helper method to reduce the budget in the ResourceManager.
     * 
     * @param amount The amount to spend (subtract from the budget).
     */
    void spendBudget(int amount) {
        ResourceManager::getInstance()->spendBudget(amount);
    }

public:
    /**
     * @brief Default constructor for UtilityFactory.
     */
    UtilityFactory() = default;

    /**
     * @brief Virtual destructor for UtilityFactory, allowing derived classes to clean up.
     */
    virtual ~UtilityFactory() = default;

    /**
     * @brief Pure virtual method to create a Utility object.
     * 
     * @param capacity The capacity of the utility.
     * @param maintenanceCost The maintenance cost associated with the utility.
     * @return Utility* Pointer to the created Utility object.
     */
    virtual Utility* createUtility(int capacity, int maintenanceCost) = 0;
};

#endif // UTILITYFACTORY_H