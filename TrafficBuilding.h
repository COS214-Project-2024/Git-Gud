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

public:
    TrafficBuilding(BuildingState *s, int capacity, TransportType transportType, int cost)
        : Building(capacity), tType(transportType) {
        buildingState = s;
        this->cost = cost;
    }

    void provideService() override {
        // Implement service specific to each TransportType, e.g., transporting citizens.
        // This could involve different handling based on `tType`.
    }

    float getCost() override {
        return static_cast<float>(cost);
    }

    TransportType getTransportType() const {
        return tType;
    }
};

#endif // TRAFFICBUILDING_H