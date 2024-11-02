#ifndef WATERFILTERINGPLANT_H
#define WATERFILTERINGPLANT_H

#include "Utility.h"

class WaterFilteringPlant : public Utility {
public:
    WaterFilteringPlant(int capacity, int maintenanceCost)
        : Utility("WaterFilteringPlant", capacity, maintenanceCost) {}

    void provideService() override {
        // Logic specific to WaterFilteringPlant, using capacity as water output
    }
};

#endif // WATERFILTERINGPLANT_H