#ifndef PUBLICSERVICE_H
#define PUBLICSERVICE_H

#include "Utility.h"

class PublicService : public Utility {
private:
    std::string serviceType;
    float funding;

public:
    PublicService(int capacity, int maintenanceCost, std::string sType, float fund) : Utility("PublicService", capacity, maintenanceCost), serviceType(sType), funding(fund){};
    virtual void provideService() = 0;
};

#endif  // PUBLICSERVICE_H