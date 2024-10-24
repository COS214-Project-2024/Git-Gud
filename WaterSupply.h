#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"

class WaterSupply : public Utility {
private:
    int waterFlowRate;

public:
    WaterSupply(int capacity, int maintenanceCost, int waterFlow);
    virtual ~WaterSupply() = default;
    void provideService() override;
};

#endif  // WATERSUPPLY_H