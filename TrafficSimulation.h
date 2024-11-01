#ifndef TRAFFICSIMULATION_H
#define TRAFFICSIMULATION_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "TrafficBuilding.h"

class TrafficSimulation {
private:
    std::unordered_map<TransportType, std::vector<std::unique_ptr<TrafficBuilding>>> trafficBuildings;

    int numTaxis;
    int numTrains;
    int numAirports;
    int numBuses;

public:
    void addTrafficBuilding(TransportType type, int capacity);

    // Initializes traffic flow if validation passes for each type
    void initializeTrafficFlow();

    //Get number of stations for a type (Use to check if there are minimum 2)
    int getNumStations(TransportType t);

    //Get number of a specific station using string value
    int getStation(TransportType type);

    //Get name of transport in string
    std::string getTransportTypeString(TransportType t); 
};

#endif // TRAFFICSIMULATION_H