#ifndef TRAFFICSIMULATION_H
#define TRAFFICSIMULATION_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "TrafficBuilding.h"

class TrafficSimulation {
private:
    std::unordered_map<TransportType, std::vector<std::unique_ptr<TrafficBuilding>>> trafficBuildings;

public:
    void addTrafficBuilding(TransportType type, int capacity);

    // Validates if there are at least two buildings of the specified type
    bool validateTrafficBuildings(TransportType type) const;

    // Initializes traffic flow if validation passes for each type
    void initializeTrafficFlow();

    std::string getTransportTypeString(TransportType t)  {
        switch(t)
        {
            case TAXI:
                return "Taxi";
                break;
            case BUS:
                return "Bus";
                break;
            case TRAIN:
                return "Train";
                break;
            case AIRPORT:
                return "Airplane";
                break;
            default:
                return "No type";
        
        }
    }
};

#endif // TRAFFICSIMULATION_H