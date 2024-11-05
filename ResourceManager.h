/**
 * @file ResourceManager.h
 * @brief Singleton class to manage various resources for buildings and utilities.
 * @version 0.1
 * @date 2024-11-04
 * 
 * @details The ResourceManager class provides methods for managing individual resources 
 *          such as wood, steel, concrete, water supply, energy supply, and waste capacity.
 *          It also provides budgeting functions for adding and spending budget.
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Resources.h"
#include <string>

class ResourceManager {
private:
    static ResourceManager* instance; ///< Singleton instance of ResourceManager.
    ResourceManager(); ///< Private constructor to enforce singleton pattern.

    Resources resources; ///< Manages individual resources.
    const int startingBudget = 500000;

public:

    /**
     * @brief Gets the singleton instance of ResourceManager.
     * 
     * @return ResourceManager* Pointer to the singleton instance.
     */
    static ResourceManager* getInstance();

    /**
     * @brief Resets the singleton instance (used for testing purposes).
     */
    static void resetInstance();


    /**
     * @brief Checks if sufficient materials are available for specific needs.
     * 
     * @param water Required water amount.
     * @param steel Required steel amount.
     * @param concrete Required concrete amount.
     * @param wood Required wood amount.
     * @param power Required energy supply.
     * @return true if sufficient materials are available.
     * @return false if resources are insufficient.
     */
    bool sufficientMaterials(int water, int steel, int concrete, int wood, int power) const;

    // Resource modification methods

     /**
     * @brief Initializes resources with specified values.
     * 
     * @param water Initial water supply.
     * @param steel Initial steel supply.
     * @param concrete Initial concrete supply.
     * @param wood Initial wood supply.
     */
    void initializeResources(int water, int steel, int concrete, int wood);

    /**
     * @brief Adds a specified amount to a given resource.
     * 
     * @param resourceType Type of resource to modify (e.g., "wood", "steel").
     * @param amount Amount to add to the resource.
     */
    void addResource(const std::string& resourceType, int amount);

    /**
     * @brief Uses a specified amount of a given resource.
     * 
     * @param resourceType Type of resource to modify (e.g., "wood", "steel").
     * @param amount Amount to subtract from the resource.
     */
    void useResource(const std::string& resourceType, int amount);

    // Specific methods for budget

    /**
     * @brief Adds an amount to the budget.
     * 
     * @param amount Amount to add to the budget.
     */
    void addBudget(int amount);

    /**
     * @brief Spends a specified amount from the budget.
     * 
     * @param amount Amount to subtract from the budget.
     */
    void spendBudget(int amount);

    // Getters

    /**
     * @brief Gets the current wood supply.
     * 
     * @return int Amount of wood available.
     */
    int getWood() const;

    /**
     * @brief Gets the current steel supply.
     * 
     * @return int Amount of steel available.
     */
    int getSteel() const;

    /**
     * @brief Gets the current concrete supply.
     * 
     * @return int Amount of concrete available.
     */
    int getConcrete() const;

    /**
     * @brief Gets the current water supply.
     * 
     * @return int Amount of water supply available.
     */
    int getBudget() const;

    /**
     * @brief Gets the current energy supply.
     * 
     * @return int Amount of energy supply available.
     */
    int getWaterSupply() const;

    /**
     * @brief Gets the current energy supply.
     * 
     * @return int Amount of energy supply available.
     */
    int getEnergySupply() const;

    /**
     * @brief Gets the current waste capacity.
     * 
     * @return int Amount of waste capacity available.
     */
    int getWasteCapacity() const;
};

#endif // RESOURCEMANAGER_H