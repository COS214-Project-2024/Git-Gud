#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utility.h"

class PowerPlant : public Utility {
public:
    PowerPlant(int capacity, int maintenanceCost)
        : Utility("PowerPlant", capacity, maintenanceCost) {}

    void callObserver() override{

        ChangeData changeData = {"ProvideService", 2.0f};

        this->notify(changeData);

    }
};

#endif // POWERPLANT_H