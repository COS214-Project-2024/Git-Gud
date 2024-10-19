#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utility.h"

class PowerPlant : public Utility
{
private:
    int powerOutput;
public:
    void provideService() override;
};


#endif // POWERPLANT_H