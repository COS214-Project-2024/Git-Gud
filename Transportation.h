/**
 * @file Transportation.h
 * @brief Defines the Transportation class for managing traffic and transport types.
 *
 * This file contains the definition of the Transportation class, which is responsible 
 * for managing various transport types and their associated traffic buildings. It provides 
 * methods for calculating traffic flow based on the capacities of these transport types, 
 * updating capacities, and adding new traffic buildings to the city.
 *
 * Dependencies:
 * - PublicService.h: Base class or interface for public service management.
 * - TrafficBuilding.h: Defines the TrafficBuilding class used within the transportation system.
 */

#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "PublicService.h"
#include "TrafficBuilding.h"

/**
 * @enum TrafficFlow
 * @brief Enum representing different traffic flows.
 */
enum TrafficFlow { LOW, MODERATE, HIGH };

/**
 * @class Transportation
 * @brief Manages traffic and transport types within a city.
 *
 * The Transportation class handles the registration and management of different types 
 * of traffic buildings. It calculates traffic flow based on the capacities of these 
 * buildings, updates transport capacities, and provides information about the current 
 * transport state.
 */
class Transportation : public Subject {
private:
    std::unordered_map<TransportType, std::vector<std::unique_ptr<TrafficBuilding>>> trafficBuildings;

    int numTaxis;
    int numTrains;
    int numAirports;
    int numBuses;

    int busCapacity;
    int taxiCapacity;
    int trainCapacity;
    int airportCapacity;

    TrafficFlow currentFlow;

public:

    /**
     * @brief Constructor for the Transportation class.
     *
     * Initializes a new instance of the Transportation class with default values.
     */
    Transportation();

    /**
     * @brief Updates the capacity of a specific transport type.
     *
     * This method increases the capacity for the given transport type by the specified amount, 
     * allowing for dynamic adjustments based on traffic demand.
     *
     * @param t The transport type to update (e.g., TAXI, BUS, TRAIN, AIRPORT).
     * @param add The amount to add to the current capacity.
     */
    void updateCapacity(TransportType t, int add);

    /**
     * @brief Calculates the current traffic flow.
     *
     * Computes the traffic flow based on the total number of citizens in the city and the 
     * capacities of all transport stations, updating the current flow state accordingly.
     */
    void calculateTrafficFlow();

    /**
     * @brief Retrieves the current traffic flow as a string.
     *
     * This method provides a human-readable string representation of the current traffic flow state.
     *
     * @param t The TrafficFlow enum value to convert to a string.
     * @return std::string A string representing the current traffic flow state.
     */
    std::string getCurrentFlow(TrafficFlow t);

    /**
     * @brief Gets the total traffic capacity for the city.
     *
     * This method sums the capacities of all transport types to provide a total traffic capacity 
     * available in the city.
     *
     * @return int The total traffic capacity of all transport buildings.
     */
    int getTotalTrafficCapacity();

    /**
     * @brief Adds a traffic building to the city.
     *
     * This method creates and adds a new traffic building of the specified type and capacity 
     * to the transportation system.
     *
     * @param type The type of transport building to add (e.g., TAXI, BUS, TRAIN, AIRPORT).
     * @param capacity The capacity of the new traffic building.
     */
    void addTrafficBuilding(TransportType type);

    /**
     * @brief Initializes traffic flow based on validation checks.
     *
     * This method validates the conditions for traffic flow initialization for each transport type 
     * and initializes the traffic flow accordingly.
     */
    void initializeTrafficFlow();

    /**
     * @brief Gets the number of stations for a specific transport type.
     *
     * This method returns the count of traffic buildings associated with the specified transport type,
     * which can be used to check if a minimum number of stations exist for proper operation.
     *
     * @param t The transport type for which to count stations.
     * @return int The number of stations for the specified transport type.
     */
    int getNumStations(TransportType t);

    /**
     * @brief Converts a transport type to its string representation.
     *
     * This method provides a human-readable string representation of the specified transport type.
     *
     * @param t The transport type to convert to a string.
     * @return std::string The string representation of the transport type.
     */
    std::string getTransportTypeString(TransportType t);
};

#endif  // TRANSPORTATION_H
