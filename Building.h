/**
 * @file Building.h
 * @author your name (you@domain.com)
 * @brief Base class of the Building hierarchy
 * @version 0.1
 * @date 2024-10-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDING_H
#define BUILDING_H

#include "Subject.h"
#include "Citizen.h"
#include "UnderConstruction.h"
#include "BuildingState.h"
#include <list>
#include <memory>
#include <future>

/// @brief Enum representing different types of businesses.
enum BusinessType {LUXURY, FOOD, GENERAL, NONE};


/// @brief Enum representing different industries.
enum Industry {MANUFACTURING, ENERGY, TECHNOLOGY};


/**
 * @class Building
 * @brief Abstract base class representing a building in a system.
 * @details Inherits from the Subject class to support observer behavior. Contains core attributes and methods that subclasses can extend.
 */
class Building : public Subject{

    protected:

        /// @brief The capacity of the building.
        int capacity;

        /// @brief State of the Building
        std::unique_ptr<BuildingState> buildingState;

        /// @brief Future object used for simulating construction asynchronously.
        std::future<void> constructionFuture; //used as part of the simulateConstruction() function

    public:

        /**
         * @brief Construct a new Building object with a specified capacity.
         * @param capacity The initial capacity of the building.
         */
        Building(int capacity);

        /**
         * @brief Construct a new Building object with default parameters.
         */
        Building();

        /**
         * @brief Destroy the Building object.
         */
        virtual ~Building();

        /// @brief Generic function that provides a service to it's Citizens (e.g. CommercialBuilding wou,,d pay it's Citizens)
        virtual void provideService()=0;

        /// @brief  Get the cost of the Building
        /// @return float
        virtual float getCost() = 0; 

        /**
         * @brief Set the state of the building.
         * @param s A unique pointer to a new BuildingState.
         */
        virtual void setState(std::unique_ptr<BuildingState> s);

        /**
         * @brief Repair the building, transitioning it to an appropriate state.
         */
        virtual void repairBuilding();

        /**
         * @brief Get the current state of the building as a string.
         * @return std::string representing the current state.
         */
        virtual std::string currentState();

        /**
         * @brief Simulate the construction process of the building asynchronously.
         */
        virtual void simulateConstruction();

        // Added these methods to ensure the type is preserved after decorated
        /**
         * @brief Get the number of stories the building has.
         * @return int representing the number of stories.
         */
        virtual int getNumStories(){return 0;};

        /**
         * @brief Get the type of business the building operates.
         * @return BusinessType representing the type of business.
         */
        virtual BusinessType getBusinessType(){return NONE;};

        /**
         * @brief Add employees to the building.
         */
        virtual void addEmployees(){};

        /**
         * @brief Get the size of the building.
         * @return int representing the size.
         */
        virtual int getSize(){return 0;};

        /**
         * @brief Get the pollution level produced by the building.
         * @return float representing the pollution level.
         */
        virtual float getPollutionLevel(){return 0;};

        /**
         * @brief Add citizens to the building.
         */
        virtual void addCitizens(){};

        /**
         * @brief Get a list of tenants (citizens) in the building.
         * @return std::list<Citizen*> representing the tenants.
         */
        virtual std::list<Citizen*> getTenants(){
            std::list<Citizen*> c;
            return c;
        };

        /**
         * @brief Add a worker to the building.
         */
        virtual void addWorker(){};

        /**
         * @brief Clone the building to create a copy.
         * @return Building* pointer to the cloned building.
         */
        virtual Building* clone()=0;

        /**
         * @brief Get the capacity of the building.
         * @return int representing the capacity.
         */
        int getCapacity();

};


#endif // BUILDING_H