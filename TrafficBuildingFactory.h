/**
 * @file TrafficBuildingFactory.h
 * @brief Defines the TrafficBuildingFactory class for creating traffic buildings.
 *
 * This file contains the definition of the TrafficBuildingFactory class, which is responsible for 
 * creating instances of TrafficBuilding. The factory method provides a way to create traffic 
 * buildings with specific types and capacities, initializing them with a default state.
 *
 * Dependencies:
 * - TrafficBuilding.h: Defines the TrafficBuilding class.
 * - BuildingState.h: Base class for different building states.
 * - BuildingFactory.h: Abstract factory class for building creation.
 * - UnderConstruction.h: Represents a specific state of a building.
 */

#ifndef TRAFFICBUILDINGFACTORY_H
#define TRAFFICBUILDINGFACTORY_H

#include "TrafficBuilding.h"
#include "BuildingState.h"
#include "BuildingFactory.h"
#include "UnderConstruction.h" // Example state class

/**
 * @class TrafficBuildingFactory
 * @brief Factory class for creating TrafficBuilding instances.
 *
 * This class inherits from BuildingFactory and provides a static method to create 
 * TrafficBuilding objects with specified types and capacities, initializing them 
 * with an initial state.
 */
class TrafficBuildingFactory : public BuildingFactory {
public:

    /**
     * @brief Creates a TrafficBuilding instance.
     *
     * This method initializes a TrafficBuilding with the specified transport type and capacity.
     * The building is set to an initial state of 'UnderConstruction' and costs are deducted 
     * from the resource manager's budget.
     *
     * @param type The transport type for the TrafficBuilding (e.g., TAXI, BUS, TRAIN, AIRPORT).
     * @param capacity The capacity of the TrafficBuilding.
     * @return TrafficBuilding* A pointer to the newly created TrafficBuilding instance.
     */
    static TrafficBuilding* createTrafficBuilding(TransportType type, int capacity) {
        int cost;
        std::unique_ptr<BuildingState> initialState = std::make_unique<UnderConstruction>();  // Default state at creation

        switch (type) {
            case TAXI:
                cost = 10000;
                break;
            case BUS:
                cost = 20000;
                break;
            case TRAIN:
                cost = 50000;
                break;
            case AIRPORT:
                cost = 100000;
                break;
            default:
                cost = 0;
        }

        ResourceManager::getInstance()->spendBudget(cost);

        return new TrafficBuilding(std::move(initialState), capacity, type, cost);
    }
};

#endif // TRAFFICBUILDINGFACTORY_H
