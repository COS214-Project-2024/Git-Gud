#ifndef HEALTHCAREFACTORY_H
#define HEALTHCAREFACTORY_H

#include "PublicServiceFactory.h"
#include "Utility.h"
#include "HealthCare.h"

class HealthCareFactory : public PublicServiceFactory {
public:
    HealthCareFactory(){};
    virtual ~HealthCareFactory(){};

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Return a new HealthCare instance
        return new HealthCare(capacity, maintenanceCost);
    }
};

#endif  // HEALTHCAREFACTORY_H