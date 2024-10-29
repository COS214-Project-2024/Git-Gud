#ifndef WATERFILTERINGPLANTFACTORY_H
#define WATERFILTERINGPLANTFACTORY_H

#include "UtilityFactory.h"
#include "WaterFilteringPlant.h"

class WaterFilteringPlantFactory : public UtilityFactory {
public:
    WaterFilteringPlantFactory() = default;
    virtual ~WaterFilteringPlantFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Create a new WaterFilteringPlant instance with capacity and maintenanceCost
        WaterFilteringPlant* plant = new WaterFilteringPlant(capacity, maintenanceCost);

        // Adjust the WaterSupply resource in ResourceManager by the plant's capacity
        adjustResource("waterSupply", capacity);

        return plant;
    }
};

#endif // WATERFILTERINGPLANTFACTORY_H
