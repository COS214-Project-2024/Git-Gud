#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "UtilityFactory.h"
#include "PowerPlant.h"

class PowerPlantFactory : public UtilityFactory {
public:
    PowerPlantFactory() = default;
    virtual ~PowerPlantFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        PowerPlant* plant = new PowerPlant(capacity, maintenanceCost);

        adjustResource("energySupply", capacity);
        spendBudget(maintenanceCost);

        return plant;
    }
};

#endif  // POWERPLANTFACTORY_H