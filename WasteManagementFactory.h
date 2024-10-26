#ifndef WASTEMANAGEMENTFACTORY_H
#define WASTEMANAGEMENTFACTORY_H

#include "UtilityFactory.h"
#include "WasteManagement.h"

class WasteManagementFactory : public UtilityFactory {
public:
    WasteManagementFactory(int capacity, int maintenanceCost, int handlingCap);
    ~WasteManagementFactory(){};

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Return a new WasteManagement instance with specific handilng capacities
        return new WasteManagement(capacity, maintenanceCost, capacity * 0.8, capacity * 0.9);
    }
};

#endif  // WASTEMANAGEMENTFACTORY_H