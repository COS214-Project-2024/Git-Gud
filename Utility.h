#ifndef UTILITY_H
#define UTILITY_H

#include <string>

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
    virtual void provideService() = 0;

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