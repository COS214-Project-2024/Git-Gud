#include "Transportation.h"
#include "TrafficBuilding.h"
#include "TrafficBuildingFactory.h"
#include "Subject.h"
#include <iostream>
#include <stdexcept>
#include <iostream>

Transportation::Transportation(){

    for(Citizen* citizen : allCitizens){

        attach(citizen);

    }

    if(allCitizens.size() > 0){

            ChangeData changeData = {"ProvideService", 8.0f};

            this->notify(changeData);   

            std::cout << "Transportation has been made available in the area" << std::endl;

    }

    
}
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

void Transportation::calculateTrafficFlow()
{
    
    int remain = getNumCitizens() - getTotalTrafficCapacity();

    if(remain > 50)
    {
        currentFlow = LOW;

    }else if(remain <= 50 && remain > 0)
    {
        currentFlow = MODERATE;

    }else if(remain <= 0)
    {
        currentFlow = HIGH;
    }

    std::cout << "Traffic Flow: " << getCurrentFlow(currentFlow) << std::endl;
  
}

std::string Transportation::getCurrentFlow(TrafficFlow t)
{
    
        switch(t)
        {
            case LOW:
                return "Low";
                break;
            case MODERATE:
                return "Moderate";
                break;
            case HIGH:
                return "High";
                break;
            default:
                return "No traffic report";
        
        }
  
}


int Transportation::getTotalTrafficCapacity(){
    
    return busCapacity + taxiCapacity + trainCapacity + airportCapacity;
}

void Transportation::addTrafficBuilding(TransportType type, int capacity) {
    auto building = TrafficBuildingFactory::createTrafficBuilding(type, capacity);
    trafficBuildings[type].push_back(std::unique_ptr<TrafficBuilding>(building));
    switch(type)
        {
            case TAXI:
                numTaxis++;
                updateCapacity(TAXI, capacity);
                break;
            case BUS:
                numBuses++;
                updateCapacity(BUS, capacity);
                break;
            case TRAIN:
                numTrains++;
                updateCapacity(TRAIN, capacity);
                break;
            case AIRPORT:
                numAirports++;
                updateCapacity(AIRPORT, capacity);
                break;
            default:
                break;
        
        }
}

void Transportation::initializeTrafficFlow() {
    // Initialize traffic flow management
    std::cout << "Traffic flow is being managed across the following buildings:" << std::endl;
    for (const auto& typePair : trafficBuildings) {
        std::cout << " - " << getNumStations(typePair.first) << " buildings of type " << getTransportTypeString(typePair.first) << std::endl;
    }
}


std::string Transportation::getTransportTypeString(TransportType t)  {
        switch(t)
        {
            case TAXI:
                return "Taxi";
                break;
            case BUS:
                return "Bus";
                break;
            case TRAIN:
                return "Train";
                break;
            case AIRPORT:
                return "Airport";
                break;
            default:
                return "No type";
        
        }
    }

    int Transportation::getNumStations(TransportType t)  {
        switch(t)
        {
            case TAXI:
                return numTaxis;
                break;
            case BUS:
                return numBuses;
                break;
            case TRAIN:
                return numTrains;
                break;
            case AIRPORT:
                return numAirports;
                break;
            default:
                return 0;
        
        }
    }

    
