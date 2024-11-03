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

    Transportation();
    //Increase amount of each transport type
    //Used to calculate the traffic flow for all the citizens using that transport type
    void updateCapacity(TransportType t, int add);

    //Calculates Traffic flow based on the total number of citizens in city and the capacity of the stations
    void calculateTrafficFlow();

    //Used to get overall transport capacity in the city
    int getTotalTrafficCapacity();

    void addTrafficBuilding(TransportType type, int capacity);

    // Initializes traffic flow if validation passes for each type
    void initializeTrafficFlow();

    //Get number of stations for a type (Use to check if there are minimum 2)
    int getNumStations(TransportType t);

    //Get name of transport in string
    std::string getTransportTypeString(TransportType t);
};

#endif  // TRANSPORTATION_H