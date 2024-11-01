#ifndef TRAFFICBUILDING_H
#define TRAFFICBUILDING_H

#include "Building.h"

enum TransportType {
    TAXI,
    BUS,
    TRAIN,
    AIRPORT
};

class TrafficBuilding : public Building {
private:
    TransportType tType;
    float cost;

public:

    TrafficBuilding(int capacity, TransportType transportType, float cost) : Building(capacity), tType(transportType), cost(cost){};

    // Updated constructor to match the factory arguments
    TrafficBuilding(BuildingState *s, int capacity, TransportType transportType, float cost)
        : Building(capacity), tType(transportType), cost(cost) {
        buildingState = s;
    }

    void provideService() override {
        std::cout << "Transportation has been provided to neighbouring buildings.\nIncrease citizen satisfaction";
        //Call function to increase satisfaction
    }

    float getCost() override {
        return cost;
    }

    TransportType getTransportType() const {
        return tType;
    }

    TrafficBuilding* clone(){
        TrafficBuilding* temp= new TrafficBuilding(this->capacity, this->getTransportType(), this->cost);
        return temp;
    }

    

};

#endif // TRAFFICBUILDING_H