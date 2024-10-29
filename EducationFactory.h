#ifndef EDUCATIONFACTORY_H
#define EDUCATIONFACTORY_H

#include "PublicServiceFactory.h"
#include "Utility.h"
#include "Education.h"

class EducationFactory : public PublicServiceFactory {
public:
    EducationFactory(){};
    virtual ~EducationFactory(){};

    Utility* createUtility(int capacity, int maintenanceCost) override {
        // Return a new Education instance
        return new Education();
    }
};

#endif  // EDUCATIONFACTORY_H