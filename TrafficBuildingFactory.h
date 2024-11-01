#ifndef TRAFFICBUILDINGFACTORY_H
#define TRAFFICBUILDINGFACTORY_H

#include "TrafficBuilding.h"
#include "BuildingState.h"
#include "UnderConstruction.h" // Example state class

class TrafficBuildingFactory {
public:
    static TrafficBuilding* createTrafficBuilding(TransportType type, int capacity) {
        int cost;
        BuildingState* initialState = new UnderConstruction();  // Default state at creation

        switch (type) {
            case TAXI:
                cost = 10000;
                break;
            case BUS:
                cost = 20000;
                break;
            case TRAIN:
                cost = 50000;
                break;
            case AIRPORT:
                cost = 100000;
                break;
            default:
                cost = 0;
        }

        return new TrafficBuilding(initialState, capacity, type, cost);
    }
};

#endif // TRAFFICBUILDINGFACTORY_H