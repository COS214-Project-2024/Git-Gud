#ifndef WATERFILTERINGPLANTFACTORY_H
#define WATERFILTERINGPLANTFACTORY_H

#include "UtilityFactory.h"
#include "WaterFilteringPlant.h"

class WaterFilteringPlantFactory : public UtilityFactory {
public:
    WaterFilteringPlantFactory() = default;
    virtual ~WaterFilteringPlantFactory() = default;

    Utility* createUtility(int capacity, int maintenanceCost) override {
        WaterFilteringPlant* plant = new WaterFilteringPlant(capacity, maintenanceCost);

        adjustResource("waterSupply", capacity);
        spendBudget(maintenanceCost);
        
        return plant;
    }

};

#endif // WATERFILTERINGPLANTFACTORY_H
