#include "TrafficSimulation.h"
#include "TrafficBuildingFactory.h"
#include <stdexcept>
#include <iostream>

void TrafficSimulation::addTrafficBuilding(TransportType type, int capacity) {
    auto building = TrafficBuildingFactory::createTrafficBuilding(type, capacity);
    trafficBuildings[type].push_back(std::unique_ptr<TrafficBuilding>(building));
}

bool TrafficSimulation::validateTrafficBuildings(TransportType type) const {
    // Check if there are at least two buildings of the specified type
    auto it = trafficBuildings.find(type);
    if (it != trafficBuildings.end() && it->second.size() >= 2) {
        return true;
    }
    return false;
}

void TrafficSimulation::initializeTrafficFlow() {
    // Check if all required types have at least two buildings
    for (const auto& typePair : trafficBuildings) {
        if (!validateTrafficBuildings(typePair.first)) {
            throw std::runtime_error("At least two buildings of each traffic type are required to start the simulation.");
        }
    }

    // Initialize traffic flow management
    std::cout << "Traffic flow is being managed across the following buildings:" << std::endl;
    for (const auto& typePair : trafficBuildings) {
        std::cout << " - " << typePair.second.size() << " buildings of type " << typePair.first << std::endl;
    }
}
