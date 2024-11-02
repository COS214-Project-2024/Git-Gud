#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"

class WasteManagement : public Utility {
public:
    WasteManagement(int capacity, int maintenanceCost)
        : Utility("WasteManagement", capacity, maintenanceCost) {}

    void callObserver() override{

        ChangeData changeData = {"ProvideService", 4.0f};

        this->notify(changeData);

        std::cout << "Waste is being managed in the area" << std::endl;

    }

};

#endif // WASTEMANAGEMENT_H