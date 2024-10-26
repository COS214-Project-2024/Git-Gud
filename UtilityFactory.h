#ifndef UTILITY_H
#define UTILITY_H

#include "Utility.h"
#include "WasteManagement.h"
#include <string>

class UtilityFactory{
    public:
        UtilityFactory();
        ~UtilityFactory(){}

        virtual Utility* createUtility(int capacity, int maintenanceCost) = 0;
};

#endif // UTILITY_H