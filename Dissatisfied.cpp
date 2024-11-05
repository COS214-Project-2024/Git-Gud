#include "Dissatisfied.h"

#include <iostream>

void Dissatisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Dissatisfied" << std::endl;
}


void Dissatisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Dissatisfied" << std::endl;
}

std::string Dissatisfied::getCurrentSatisfactionLevel()
{
    return "Dissatisfied";
}