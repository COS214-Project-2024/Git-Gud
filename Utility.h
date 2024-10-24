#ifndef UTILITY_H
#define UTILITY_H

#include <string>

class Utility {
    protected:
        std::string utilityType; // Type of utility (e.g., "Power", "Water", etc.)
        int capacity;             // Capacity of the utility (e.g., energy output, water flow)
        int maintenanceCost;      // Cost for maintaining the utility
    
    public:
        Utility(const std::string& type, int cap, int cost);
        virtual ~Utility() = default;
        virtual void provideService() = 0;  // Pure virtual function
        std::string getUtilityType() const;
        int getCapacity() const;
        int getMaintenanceCost() const;
};

#endif // UTILITY_H