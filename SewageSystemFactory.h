#ifndef SEWAGESYSTEMFACTORY_H
#define SEWAGESYSTEMFACTORY_H

#include "UtilityFactory.h"
#include "SewageSystem.h"

class SewageSystemFactory : public UtilityFactory {
public:
    SewageSystemFactory() = default;
    virtual ~SewageSystemFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        SewageSystem* sewageSystem = new SewageSystem(capacity, maintenanceCost);
        adjustResource("waterSupply", capacity);  // or the appropriate resource
        return sewageSystem;
    }
};

#endif // SEWAGESYSTEMFACTORY_H