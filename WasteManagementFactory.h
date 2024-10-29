#ifndef WASTEMANAGEMENTFACTORY_H
#define WASTEMANAGEMENTFACTORY_H

#include "UtilityFactory.h"
#include "WasteManagement.h"

class WasteManagementFactory : public UtilityFactory {
public:
    WasteManagementFactory() = default;
    virtual ~WasteManagementFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Create a new WasteManagement instance with capacity interpreted as filtering capability
        WasteManagement* wasteManagement = new WasteManagement(capacity, maintenanceCost);

        // Adjust the waste capacity resource in ResourceManager
        adjustResource("wasteCapacity", capacity);

        return wasteManagement;
    }
};

#endif // WASTEMANAGEMENTFACTORY_H