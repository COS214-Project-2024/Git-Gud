#ifndef WATERFILTERINGPLANT_H
#define WATERFILTERINGPLANT_H

#include "Utility.h"

class WaterFilteringPlant : public Utility {
public:
    WaterFilteringPlant(int capacity, int maintenanceCost)
        : Utility("WaterFilteringPlant", capacity, maintenanceCost) {}

    void callObserver() override{

        ChangeData changeData = {"ProvideService", 3.0f};

        this->notify(changeData);

        std::cout << "Waterfiltering is done for all the water in the area" << std::endl;

    }
};

#endif // WATERFILTERINGPLANT_H