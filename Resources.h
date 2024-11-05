/**
 * @file Resources.h
 * @brief Manages individual resource types (e.g., Wood, Steel, WaterSupply) in the system.
 * @version 0.1
 * @date 2024-11-01
 * 
 * @details The Resources class serves as a container for various resource types,
 *          providing methods to get and set the amounts for each resource. It is
 *          designed to be accessed exclusively by the ResourceManager class.
 */

#ifndef RESOURCES_H
#define RESOURCES_H

#include "Wood.h"
#include "Steel.h"
#include "Concrete.h"
#include "WaterSupply.h"
#include "EnergySupply.h"
#include "Budget.h"
#include "WasteCapacity.h"

class Resources {
private:
    Wood wood;                    /**< Manages the wood resource */
    Steel steel;                  /**< Manages the steel resource */
    Concrete concrete;            /**< Manages the concrete resource */
    WaterSupply waterSupply;      /**< Manages the water supply resource */
    EnergySupply energySupply;    /**< Manages the energy supply resource */
    Budget budget;                /**< Manages the budget resource */
    WasteCapacity wasteCapacity;  /**< Manages the waste capacity resource */

public:
    /**
     * @brief Construct a new Resources object with optional initial values.
     * 
     * @param w Initial wood amount.
     * @param s Initial steel amount.
     * @param c Initial concrete amount.
     * @param ws Initial water supply amount.
     * @param es Initial energy supply amount.
     * @param b Initial budget amount.
     * @param wc Initial waste capacity amount.
     */
    Resources(int w = 0, int s = 0, int c = 0, int ws = 0, int es = 0, int b = 0, int wc = 0)
        : wood(w), steel(s), concrete(c), waterSupply(ws), energySupply(es), budget(b), wasteCapacity(wc) {}

    /**
     * @brief Get a non-const reference to the wood resource.
     * @return Wood& Reference to the wood resource.
     */
    Wood& getWoodResource() { return wood; }

    /**
     * @brief Get a non-const reference to the steel resource.
     * @return Steel& Reference to the steel resource.
     */
    Steel& getSteelResource() { return steel; }

    /**
     * @brief Get a non-const reference to the concrete resource.
     * @return Concrete& Reference to the concrete resource.
     */
    Concrete& getConcreteResource() { return concrete; }

    /**
     * @brief Get a non-const reference to the water supply resource.
     * @return WaterSupply& Reference to the water supply resource.
     */
    WaterSupply& getWaterSupplyResource() { return waterSupply; }

    /**
     * @brief Get a non-const reference to the energy supply resource.
     * @return EnergySupply& Reference to the energy supply resource.
     */
    EnergySupply& getEnergySupplyResource() { return energySupply; }

    /**
     * @brief Get a non-const reference to the budget resource.
     * @return Budget& Reference to the budget resource.
     */
    Budget& getBudgetResource() { return budget; }

    /**
     * @brief Get a non-const reference to the waste capacity resource.
     * @return WasteCapacity& Reference to the waste capacity resource.
     */
    WasteCapacity& getWasteCapacityResource() { return wasteCapacity; }

    /**
     * @brief Get a const reference to the wood resource.
     * @return const Wood& Const reference to the wood resource.
     */
    const Wood& getWoodResource() const { return wood; }

    /**
     * @brief Get a const reference to the steel resource.
     * @return const Steel& Const reference to the steel resource.
     */
    const Steel& getSteelResource() const { return steel; }

    /**
     * @brief Get a const reference to the concrete resource.
     * @return const Concrete& Const reference to the concrete resource.
     */
    const Concrete& getConcreteResource() const { return concrete; }

    /**
     * @brief Get a const reference to the water supply resource.
     * @return const WaterSupply& Const reference to the water supply resource.
     */
    const WaterSupply& getWaterSupplyResource() const { return waterSupply; }

    /**
     * @brief Get a const reference to the energy supply resource.
     * @return const EnergySupply& Const reference to the energy supply resource.
     */
    const EnergySupply& getEnergySupplyResource() const { return energySupply; }

    /**
     * @brief Get a const reference to the budget resource.
     * @return const Budget& Const reference to the budget resource.
     */
    const Budget& getBudgetResource() const { return budget; }

    /**
     * @brief Get a const reference to the waste capacity resource.
     * @return const WasteCapacity& Const reference to the waste capacity resource.
     */
    const WasteCapacity& getWasteCapacityResource() const { return wasteCapacity; }

    /**
     * @brief Set the initial wood amount.
     * @param amount New wood amount.
     */
    void setWood(int amount) { wood.setAmount(amount); }

    /**
     * @brief Set the initial steel amount.
     * @param amount New steel amount.
     */
    void setSteel(int amount) { steel.setAmount(amount); }

    /**
     * @brief Set the initial concrete amount.
     * @param amount New concrete amount.
     */
    void setConcrete(int amount) { concrete.setAmount(amount); }

    /**
     * @brief Set the initial water supply amount.
     * @param amount New water supply amount.
     */
    void setWaterSupply(int amount) { waterSupply.setAmount(amount); }

    /**
     * @brief Set the initial energy supply amount.
     * @param amount New energy supply amount.
     */
    void setEnergySupply(int amount) { energySupply.setAmount(amount); }

    /**
     * @brief Set the initial budget amount.
     * @param amount New budget amount.
     */
    void setBudget(int amount) { budget.setAmount(amount); }

    /**
     * @brief Set the initial waste capacity amount.
     * @param amount New waste capacity amount.
     */
    void setWasteCapacity(int amount) { wasteCapacity.setAmount(amount); }
};

#endif // RESOURCES_H