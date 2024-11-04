/**
 * @file TrafficBuilding.h
 * @brief Defines the TrafficBuilding class, representing a building dedicated to transportation services.
 *
 * This file contains the definition of the TrafficBuilding class, which is a subclass of Building.
 * The TrafficBuilding class models a building that provides various transportation services,
 * represented by the TransportType enum. It provides methods for retrieving the transportation
 * type, the cost, and cloning the building, as well as for providing transportation services.
 *
 * Dependencies:
 * - Building.h: Base class for buildings.
 */

#ifndef TRAFFICBUILDING_H
#define TRAFFICBUILDING_H

#include "Building.h"

/**
 * @enum TransportType
 * @brief Enum representing different types of transport services.
 */
enum TransportType {
    TAXI,    
    BUS,     
    TRAIN,   
    AIRPORT 
};

/**
 * @class TrafficBuilding
 * @brief Represents a building that provides transportation services.
 *
 * This class inherits from Building and represents a building dedicated to transportation.
 * It includes a transport type, cost, and methods for providing services, retrieving transport
 * type and cost, and cloning the building instance.
 */
class TrafficBuilding : public Building {
private:
    /**
     * @brief The type of transport service provided by the building.
     */
    TransportType tType;

    /**
     * @brief The cost associated with the traffic building.
     */
    float cost;

public:
    /**
     * @brief Constructor for TrafficBuilding with specified capacity, transport type, and cost.
     * @param capacity The capacity of the building.
     * @param transportType The type of transportation provided.
     * @param cost The cost associated with the traffic building.
     */
    TrafficBuilding(int capacity, TransportType transportType, float cost) 
        : Building(capacity), tType(transportType), cost(cost) {}

    /**
     * @brief Constructor for TrafficBuilding with state, capacity, transport type, and cost.
     * @param s A unique pointer to a BuildingState object representing the initial state.
     * @param capacity The capacity of the building.
     * @param transportType The type of transportation provided.
     * @param cost The cost associated with the traffic building.
     */
    TrafficBuilding(std::unique_ptr<BuildingState> s, int capacity, TransportType transportType, float cost)
        : Building(capacity), tType(transportType), cost(cost) {
        setState(std::move(s));
    }

    /**
     * @brief Provides transportation services and increases citizen satisfaction.
     *
     * This method outputs a message indicating that transportation services have been provided
     * to neighboring buildings and increases citizen satisfaction.
     */
    void provideService() override {
        std::cout << "Transportation has been provided to neighbouring buildings.\nIncrease citizen satisfaction";
        // Call function to increase satisfaction
    }

    /**
     * @brief Retrieves the cost of the traffic building.
     * @return The cost of the traffic building as a float.
     */
    float getCost() override {
        return cost;
    }

    /**
     * @brief Retrieves the type of transportation provided by the building.
     * @return The transport type as a TransportType enum value.
     */
    TransportType getTransportType() const {
        return tType;
    }

    /**
     * @brief Creates a clone of the current TrafficBuilding instance.
     * @return A pointer to the cloned TrafficBuilding object.
     */
    TrafficBuilding* clone() {
        TrafficBuilding* temp = new TrafficBuilding(this->capacity, this->getTransportType(), this->cost);
        return temp;
    }
};

#endif // TRAFFICBUILDING_H
