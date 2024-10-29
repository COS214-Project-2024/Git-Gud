#ifndef LAWENFORCEMENTFACTORY_H
#define LAWENFORCEMENTFACTORY_H

#include "PublicServiceFactory.h"
#include "Utility.h"
#include "LawEnforcement.h"

class LawEnforcementFactory : public PublicServiceFactory {
public:
    LawEnforcementFactory(){};
    virtual ~LawEnforcementFactory(){};

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Return a new LawEnforcement instance
        return new LawEnforcement();
    }
};

#endif  // LAWENFORCEMENTFACTORY_H