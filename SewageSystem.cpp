#include "SewageSystem.h"
#include <iostream>

void SewageSystem::provideService()
{
    std::cout << "SewageSystem has been provided to neighbouring buildings.\nIncrease citizen satisfaction";
    //Call function to increase satisfaction
}

int SewageSystem::getFilteringCapacity() const
{
    return filteringCapacity;
}