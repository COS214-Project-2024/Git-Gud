#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "Utility.h"

class SewageSystem : public Utility {
public:
    SewageSystem(int capacity, int maintenanceCost)
        : Utility("SewageSystem", capacity, maintenanceCost) {}

    void provideService() override {
        // Logic specific to WasteManagement, using capacity as filtering capability
    }
};

#endif  // SEWAGESYSTEM_H