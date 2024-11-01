#include "Transportation.h"
#include <iostream>

void Transportation::updateCapacity(TransportType t, int add)
{
    switch(t)
        {
            case TAXI:
                taxiCapacity += add;
                break;
            case BUS:
                busCapacity += add;
                break;
            case TRAIN:
                trainCapacity += add;
                break;
            case AIRPORT:
                airportCapacity += add;
                break;
            default:
                break;
        
        }
}