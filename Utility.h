/**
 * @file Utility.h
 * @brief Base class for various utility types (e.g., PowerPlant, WaterFilteringPlant).
 * @version 0.1
 * @date 2024-11-01
 * 
 * @details The Utility class is an abstract class that defines the structure for all utilities,
 *          including attributes for utility type, capacity, and maintenance cost. Each specific
 *          utility type will implement observer notifications and unique service provisions.
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "Subject.h"
#include "Building.h"

class Citizen;

class Utility : public Subject {
protected:
    std::string utilityType; ///< Type of utility (e.g., "PowerPlant", "WaterFilteringPlant").
    int capacity; ///< General capacity for the utility (e.g., output, filtering capacity).
    int maintenanceCost; ///< Cost for maintaining the utility.

public:
    /**
     * @brief Constructs a new Utility object with specified parameters.
     * 
     * @param type Type of utility.
     * @param cap Capacity of the utility.
     * @param cost Maintenance cost for the utility.
     */
    Utility(const std::string& type, int cap, int cost)
        : utilityType(type), capacity(cap), maintenanceCost(cost) {}

    /**
     * @brief Virtual destructor for Utility, allowing derived classes to clean up.
     */
    virtual ~Utility() = default;

    /**
     * @brief Pure virtual function to notify observers, to be implemented by derived classes.
     */
    virtual void callObserver() = 0;

    /**
     * @brief Gets the capacity of the utility.
     * 
     * @return int The capacity, interpretation depends on specific utility type.
     */
    int getCapacity() const { 
        return capacity; 
    }

    /**
     * @brief Gets the maintenance cost of the utility.
     * 
     * @return int Maintenance cost for the utility.
     */
    int getMaintenanceCost() const { 
        return maintenanceCost; 
    }

    /**
     * @brief Gets the type of utility.
     * 
     * @return std::string The utility type as a string.
     */
    std::string getUtilityType() const { 
        return utilityType; 
    }

    /**
     * @brief Manages and updates observers associated with the utility.
     * 
     * @details Attaches all citizens to the observer list and calls `callObserver` if 
     *          there are observers present.
     */
    void scanBuilding(Building* building){

        for(Citizen* citizen : building->getObserverList()){

            this->attach(citizen);

        }

    }
};

#endif // UTILITY_H
