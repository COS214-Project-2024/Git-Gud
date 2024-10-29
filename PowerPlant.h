#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utility.h"

class PowerPlant : public Utility {
public:
    PowerPlant(int capacity, int maintenanceCost)
        : Utility("PowerPlant", capacity, maintenanceCost) {}

    void provideService() override {
        // Logic specific to PowerPlant, using capacity as energy output
    }
};

#endif // POWERPLANT_H