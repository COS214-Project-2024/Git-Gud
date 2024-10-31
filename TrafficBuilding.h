#ifndef TRAFFICBUILDING_H
#define TRAFFICBUILDING_H

#include "Building.h"

enum TransportType {
    TAXI,
    BUS,
    TRAIN,
    AIRPLANE
};

class TrafficBuilding : public Building {
private:
    TransportType tType;
    float cost;

public:
    // Updated constructor to match the factory arguments
    TrafficBuilding(BuildingState *s, int capacity, TransportType transportType, float cost)
        : Building(capacity), tType(transportType), cost(cost) {
        buildingState = s;
    }

    void provideService() override {
        // Implement service specific to each TransportType
    }

    float getCost() override {
        return cost;
    }

    TransportType getTransportType() const {
        return tType;
    }
};

#endif // TRAFFICBUILDING_H