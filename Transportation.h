#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include "PublicService.h"

class Transportation: public PublicService
{
private:
    int roadCapacity, busCapacity, trainCapacity, taxiCapacity, airportCapacity;
public:
    void provideService();
    void manageTraficFlow();
    void calculateCommuteTimes();
};

#endif // TRANSPORTATION_H