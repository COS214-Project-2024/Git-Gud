#ifndef TRAFFICSIMULATION_H
#define TRAFFICSIMULATION_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "TrafficBuilding.h"

class TrafficSimulation {
private:
    // Stores traffic buildings by type
    std::unordered_map<TransportType, std::vector<std::unique_ptr<TrafficBuilding>>> trafficBuildings;

public:
    // Adds a new TrafficBuilding to the simulation
    void addTrafficBuilding(TransportType type, int capacity);

    // Ensures at least two of each TrafficBuilding type are present
    bool validateTrafficBuildings() const;

    // Initializes traffic flow if validation passes
    void initializeTrafficFlow();
};

#endif // TRAFFICSIMULATION_H
