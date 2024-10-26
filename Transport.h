#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "PublicService.h"

class Transport : public PublicService {
private:
    int roadCapacity;
    int busCapacity;
    int taxiCapacity;
    int trainCapacity;
    int airportCapacity;
public:
    void provideService() override;
    //void manageTrafficFlow();
    //void calculateCommuteTimes();
};

#endif  // TRANSPORT_H