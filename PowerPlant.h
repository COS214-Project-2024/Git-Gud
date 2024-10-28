#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utility.h"

class PowerPlant : public Utility {
    private:
        int energyOutput;

    public:
        PowerPlant(int capacity, int maintenanceCost, int energyOut) : Utility("PowerPlant", capacity, maintenanceCost), energyOutput(energyOut){}
        virtual ~PowerPlant() = default;
        
        void provideService() override;
};

#endif  // POWERPLANT_H