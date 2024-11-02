#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"

class WasteManagement : public Utility {
public:
    WasteManagement(int capacity, int maintenanceCost)
        : Utility("WasteManagement", capacity, maintenanceCost) {}

    void provideService() override {
        // Logic specific to WasteManagement, using capacity as filtering capability
    }
};

#endif // WASTEMANAGEMENT_H