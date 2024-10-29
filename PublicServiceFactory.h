#ifndef PUBLICSERVICEFACTORY_H
#define PUBLICSERVICEFACTORY_H

#include "UtilityFactory.h"
#include "Utility.h"

class PublicServiceFactory : public UtilityFactory {
public:
    PublicServiceFactory(){};
    virtual ~PublicServiceFactory(){};

    virtual Utility* createUtility(int capacity, int maintenanceCost) = 0;
};

#endif  // PUBLICSERVICEFACTORY_H