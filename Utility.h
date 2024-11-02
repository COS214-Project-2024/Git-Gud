#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "Subject.h"
#include "GameEnvironment.h"

class Utility : public Subject {
protected:
    std::string utilityType; // Type of utility (e.g., "PowerPlant", "WaterFilteringPlant")
    int capacity;            // General capacity (output, filtering, etc.)
    int maintenanceCost;     // Cost for maintaining the utility

public:
    Utility(const std::string& type, int cap, int cost)
        : utilityType(type), capacity(cap), maintenanceCost(cost) {}
    virtual ~Utility() = default;

    // Pure virtual function for service provision
    //virtual void provideService(GameEnvironment* environment, int utilityX, int utilityY, int radius = 2) = 0;

    void provideService(GameEnvironment* environment, int utilityX, int utilityY, int radius = 2){

        for(int i = utilityX - radius; i <= utilityX + radius; ++i){

            for(int j = utilityY - radius; j <= utilityY + radius; ++j){

                if(i >= 0 && i < environment->getRows() && j >= 0 && j < environment->getCols()){
                    
                    Building* building = environment->getBuildingAt(i, j);

                    if(building != nullptr){

                        std::vector<Citizen*> buildingObservers = building->getObserverList();

                        for(Citizen* citizen : buildingObservers){

                            this->attach(citizen);

                        }

                    }
                }
            }
        }

        this->callObserver();

    }
    
    virtual void callObserver() = 0;

    // Getter for capacity (interpretation is utility-specific)
    int getCapacity() const { 
        return capacity; 
    }

    // Getter for maintenance cost
    int getMaintenanceCost() const { 
        return maintenanceCost; 
    }

    std::string getUtilityType() const { 
        return utilityType; 
    }
};

#endif // UTILITY_H