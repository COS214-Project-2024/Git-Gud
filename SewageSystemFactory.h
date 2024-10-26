#ifndef SEWAGESYSTEMFACTORY_H
#define SEWAGESYSTEMFACTORY_H

#include "UtilityFactory.h"
#include "SewageSystem.h"

class SewageSystemFactory : public UtilityFactory {
public:
    SewageSystemFactory(int capacity, int maintenanceCost, int filteringCap);

    Utility* createUtility() override;

private:
    int capacity;
    int maintenanceCost;
    int filteringCapacity;
};

#endif  // SEWAGESYSTEMFACTORY_H