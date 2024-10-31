#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include "PublicService.h"

class Transportation : public PublicService {
private:
    int busCapacity;
    int taxiCapacity;
    int trainCapacity;
    int airportCapacity;
public:
    void manageTrafficFlow();
    void calculateCommuteTimes();
};

#endif  // TRANSPORTATION_H