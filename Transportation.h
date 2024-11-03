#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "PublicService.h"
#include "TrafficBuilding.h"

enum TrafficFlow{LOW, MODERATE, HIGH};
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
        * @brief Constructor of Transportation
        * @return
    **/
    Transportation();

    /**
        * @brief Update the capacity of a transport type
        * @param t
        * @param add
        * @return
    **/
    //Increase amount of each transport type
    //Used to calculate the traffic flow for all the citizens using that transport type
    void updateCapacity(TransportType t, int add);

    /**
        * @brief Calculate traffic flow based on the total number of citizens in city and the capacity of the stations
        * @return
    **/
    void calculateTrafficFlow();

    /**
        * @brief Get current trafficFlow string name
        * @param t
        * @return string
    **/
    std::string getCurrentFlow(TrafficFlow t);

    /**
        * @brief Get total traffic capacity for the city
        * @return int
    **/
    int getTotalTrafficCapacity();

    /**
        * @brief Add a traffic building to the city
        * @param type
        * @param capacity
        * @return 
    **/
    void addTrafficBuilding(TransportType type, int capacity);

    /**
        * @brief Initializes traffic flow if validation passes for each type
        * @return 
    **/
    void initializeTrafficFlow();

    /**
        * @brief Get number of stations for a type (Use to check if there are minimum 2)
        * @param t
        * @return int
    **/
    int getNumStations(TransportType t);

    /**
        * @brief Get name of transport in string
        * @param t
        * @return string
    **/
    //
    std::string getTransportTypeString(TransportType t);
};

#endif  // TRANSPORTATION_H