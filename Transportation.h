#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include "PublicService.h"
#include "TrafficBuilding.h"

class Transportation : public PublicService {
private:
    int busCapacity;
    int taxiCapacity;
    int trainCapacity;
    int airportCapacity;
public:
    //Increase amount of each transport type
    //Used to calculate the traffic flow for all the citizens using that transport type
    void updateCapacity(TransportType t, int add);
};

#endif  // TRANSPORTATION_H