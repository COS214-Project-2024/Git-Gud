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
    /**
        * @brief Constructor of traffic building 
        * @param transportType
        * @param capacity
        * @param cost
        * @return
    **/
    TrafficBuilding(int capacity, TransportType transportType, float cost) : Building(capacity), tType(transportType), cost(cost){};

    /**
        * @brief Another constructor of traffic building 
        * @param s
        * @param capacity
        * @param transportType
        * @param cost
        * @return
    **/
    // Updated constructor to match the factory arguments
    TrafficBuilding(std::unique_ptr<BuildingState> s, int capacity, TransportType transportType, float cost)
        : Building(capacity), tType(transportType), cost(cost) {
        setState(std::move(s));
    }

    void provideService() override {
        std::cout << "Transportation has been provided to neighbouring buildings.\nIncrease citizen satisfaction";
        //Call function to increase satisfaction
    }

    /**
        * @brief Get the cost of traffic building
        * @return float
    **/
    float getCost() override {
        return cost;
    }

    /**
        * @brief Get the transport type of traffic building
        * @return TransportType
    **/
    TransportType getTransportType() const {
        return tType;
    }

    /**
        * @brief Clone the current traffic building
        * @return TrafficBuilding*
    **/
    TrafficBuilding* clone(){
        TrafficBuilding* temp= new TrafficBuilding(this->capacity, this->getTransportType(), this->cost);
        return temp;
    }

    

};

#endif // TRAFFICBUILDING_H