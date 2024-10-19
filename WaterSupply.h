#ifndef WATER_SUPPLY_H
#define WATER_SUPPLY_H

#include "Utility.h"

class WaterSupply : public Utility
{
private:
    int waterFlowRate;
public:
    void provideService() override;
};


#endif // WATER_SUPPLY_H