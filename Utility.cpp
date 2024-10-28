#include "Utility.h"
#include <iostream>

std::string Utility::getUtilityType() const
{
    return utilityType;
}
        
int Utility::getCapacity() const
{
    return capacity;
}
        
int Utility::getMaintenanceCost() const
{
    return maintenanceCost;
}