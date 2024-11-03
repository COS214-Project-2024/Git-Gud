#ifndef WASTEMANAGEMENTFACTORY_H
#define WASTEMANAGEMENTFACTORY_H

#include "UtilityFactory.h"
#include "WasteManagement.h"

class WasteManagementFactory : public UtilityFactory {
public:
    WasteManagementFactory() = default;
    virtual ~WasteManagementFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        WasteManagement* waste = new WasteManagement(capacity, maintenanceCost);

        adjustResource("wasteCapacity", capacity);
        spendBudget(maintenanceCost);

        return waste;
    }
};

#endif // WASTEMANAGEMENTFACTORY_H