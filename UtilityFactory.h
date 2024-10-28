#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "Utility.h"
#include "WasteManagement.h"
#include <string>

class UtilityFactory {
    public:
        UtilityFactory();
        virtual ~UtilityFactory(){}

        virtual Utility* createUtility(int capacity, int maintenanceCost) = 0;
};

#endif // UTILITYFACTORY_H