#ifndef POWERPLANTFACTORY_h
#define POWERPLANTFACTORY_h

#include "UtilityFactory.h"
#include "Utility.h"
#include "PowerPlant.h"

class PowerPlantFactory : public UtilityFactory {
public:
    PowerPlantFactory(int capacity, int maintenanceCost, int energyOut);
    virtual ~PowerPlantFactory(){};

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Return a new Powerplant instance with specific power output
        return new PowerPlant(capacity, maintenanceCost, capacity * 0.8);
    }
};

#endif  // POWERPLANTFACTORY_h