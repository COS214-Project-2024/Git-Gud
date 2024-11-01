#include "TrafficSimulation.h"
#include "TrafficBuilding.h"
#include "TrafficBuildingFactory.h"
#include <stdexcept>
#include <iostream>

void TrafficSimulation::addTrafficBuilding(TransportType type, int cost) {
    auto building = TrafficBuildingFactory::createTrafficBuilding(type, cost);
    trafficBuildings[type].push_back(std::unique_ptr<TrafficBuilding>(building));
    switch(type)
        {
            case TAXI:
                numTaxis++;
                break;
            case BUS:
                numBuses++;
                break;
            case TRAIN:
                numTrains++;
                break;
            case AIRPORT:
                numAirports++;
                break;
            default:
                break;
        
        }
}

void TrafficSimulation::initializeTrafficFlow() {
    // Initialize traffic flow management
    std::cout << "Traffic flow is being managed across the following buildings:" << std::endl;
    for (const auto& typePair : trafficBuildings) {
        std::cout << " - " << getNumStations(typePair.first) << " buildings of type " << getTransportTypeString(typePair.first) << std::endl;
    }
}

int TrafficSimulation::getStation(TransportType type)
{
    switch(type)
        {
            case TAXI:
                return numTaxis;
                break;
            case BUS:
                return numBuses;
                break;
            case TRAIN:
                return numTrains;
                break;
            case AIRPORT:
                return numAirports;
                break;
            default:
                return 0;
                break;
        
        }
}

    std::string TrafficSimulation::getTransportTypeString(TransportType t)  {
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

    int TrafficSimulation::getNumStations(TransportType t)  {
        switch(t)
        {
            case TAXI:
                return numTaxis;
                break;
            case BUS:
                return numBuses;
                break;
            case TRAIN:
                return numTrains;
                break;
            case AIRPORT:
                return numAirports;
                break;
            default:
                return 0;
                break;
        
        }
    }
