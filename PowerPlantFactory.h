#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "UtilityFactory.h"
#include "PowerPlant.h"

class PowerPlantFactory : public UtilityFactory {
public:
    PowerPlantFactory() = default;
    virtual ~PowerPlantFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Create a new PowerPlant instance with only the two required parameters
        PowerPlant* plant = new PowerPlant(capacity, maintenanceCost);

        // Adjust the power resource upon creation of the PowerPlant
        adjustResource("energySupply", capacity);

        return plant;
    }
};

#endif  // POWERPLANTFACTORY_H