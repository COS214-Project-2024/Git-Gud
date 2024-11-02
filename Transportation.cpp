#include "Transportation.h"
#include "Subject.h"
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

TrafficFlow Transportation::calculateTrafficFlow()
{
    /*
    int remain = getNumCitizens() % getNumStations();

    switch(remain)
    {
        case remain == 0:
            currentFlow = HIGH;
        break;

        case remain < 1:
            currentFlow = MODERATE;
        break;

        case remain > 1:
            currentFlow = LOW;
    }
    */
}

void Transportation::callObserver(){

    ChangeData changeData = {"ProvideService", 8.0f};

    this->notify(changeData);   

    std::cout << "Transportation has been made available in the area" << std::endl;

}