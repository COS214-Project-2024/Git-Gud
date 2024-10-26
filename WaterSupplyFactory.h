#ifndef WATERSUPPLYFACTORY_H
#define WATERSUPPLYFACTORY_H

#include "UtilityFactory.h"
#include "WaterSupply.h"

class WaterSupplyFactory : public UtilityFactory {
public:
    WaterSupplyFactory(int capacity, int maintenanceCost, int waterflow);
    ~WaterSupplyFactory(){};

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Return a new WaterSupply instance with specific filtering and garbage capacities
        return new WaterSupply(capacity, maintenanceCost, capacity * 0.8);
    }
};

#endif  // WATERSUPPLYFACTORY_H