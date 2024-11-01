#include "TrafficSimulation.h"
#include "TrafficBuildingFactory.h"
#include <stdexcept>
#include <iostream>

void TrafficSimulation::addTrafficBuilding(TransportType type, int capacity) {
    // Use the factory to create a new TrafficBuilding of the specified type
    auto building = TrafficBuildingFactory::createTrafficBuilding(type, capacity);
    trafficBuildings[type].push_back(std::unique_ptr<TrafficBuilding>(building));
}

bool TrafficSimulation::validateTrafficBuildings() const {
    // Check if there are at least two buildings of each type
    for (const auto& typePair : trafficBuildings) {
        if (typePair.second.size() < 2) {
            return false; // If any type has fewer than 2, validation fails
        }
    }
    return true;
}

void TrafficSimulation::initializeTrafficFlow() {
    if (!validateTrafficBuildings()) {
        throw std::runtime_error("At least two buildings of each traffic type are required to start the simulation.");
    }
    
    // Initialize traffic flow management
    std::cout << "Traffic flow is being managed across the following buildings:" << std::endl;
    for (const auto& typePair : trafficBuildings) {
        std::cout << " - " << typePair.second.size() << " buildings of type " << typePair.first << std::endl;
    }
}