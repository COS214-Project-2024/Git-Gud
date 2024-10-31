#ifndef TRAFFICBUILDING_H
#define TRAFFICBUILDING_H

#include "Building.h"

enum TransportType {
    TAXI,
    BUS,
    TRAIN,
    AIRPLANE
};

class TrafficBuilding: public Building{

    private:
        TransportType tType;
        float cost;
    public:

    protected: 
        TrafficBuilding(BuildingState *s, int capacity, float cost, TransportType transportType);

        virtual void provideService() override;

        virtual float getCost() override;

};

#endif // TRAFFICBUILDING_H