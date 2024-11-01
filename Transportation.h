#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include "PublicService.h"
#include "TrafficBuilding.h"

enum TrafficFlow{LOW, MODERATE, HIGH};
class Transportation : public PublicService {
private:
    int busCapacity;
    int taxiCapacity;
    int trainCapacity;
    int airportCapacity;

    TrafficFlow currentFlow;
public:
    //Increase amount of each transport type
    //Used to calculate the traffic flow for all the citizens using that transport type
    void updateCapacity(TransportType t, int add);

    //Calculates Traffic flow based on the total number of citizens in city and the capacity of the stations
    TrafficFlow calculateTrafficFlow();
};

#endif  // TRANSPORTATION_H