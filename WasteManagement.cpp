#include "WasteManagement.h"
#include <iostream>


int WasteManagement::getHandlingCapacity() const
{
    return handlingCapacity;
}

void WasteManagement::provideService()
{
    std::cout << "WasteManagement has been provided to neighbouring buildings.\nIncrease citizen satisfaction";
    //Call function to increase satisfaction
}