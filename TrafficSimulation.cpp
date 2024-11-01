#include "TrafficSimulation.h"
#include "TrafficBuilding.h"
#include "TrafficBuildingFactory.h"
#include <stdexcept>
#include <iostream>

void TrafficSimulation::addTrafficBuilding(TransportType type, int cost) {
    auto building = TrafficBuildingFactory::createTrafficBuilding(type, cost);
    trafficBuildings[type].push_back(std::unique_ptr<TrafficBuilding>(building));
}

void TrafficSimulation::initializeTrafficFlow() {
    // Initialize traffic flow management
    std::cout << "Traffic flow is being managed across the following buildings:" << std::endl;
    for (const auto& typePair : trafficBuildings) {
        std::cout << " - " << typePair.second.size() << " buildings of type " << getTransportTypeString(typePair.first) << std::endl;
    }
}
