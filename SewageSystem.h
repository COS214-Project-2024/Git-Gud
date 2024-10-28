#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "Utility.h"

class SewageSystem : public Utility {
protected:
    int filteringCapacity;  // Capacity to filter sewage

public:
    SewageSystem(int capacity, int maintenanceCost, int filteringCap) : Utility("SewageSystem", capacity, maintenanceCost), filteringCapacity(filteringCap){};
    virtual ~SewageSystem() = default;

    void provideService() override;

    int getFilteringCapacity() const;
};

#endif  // SEWAGESYSTEM_H