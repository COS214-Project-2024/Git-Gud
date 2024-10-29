#ifndef SEWAGESYSTEMFACTORY_H
#define SEWAGESYSTEMFACTORY_H

#include "UtilityFactory.h"
#include "SewageSystem.h"

class SewageSystemFactory : public UtilityFactory {
public:
    SewageSystemFactory() = default;
    virtual ~SewageSystemFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Create a new SewageSystem instance with specific water flow capacities
        SewageSystem* sewageSystem = new SewageSystem(capacity, maintenanceCost, capacity * 2);

        // Adjust the wasteCapacity resource
        adjustResource("wasteCapacity", capacity);

        return sewageSystem;
    }
};

#endif // SEWAGESYSTEMFACTORY_H