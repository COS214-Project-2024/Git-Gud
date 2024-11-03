#include "VerySatisfied.h"

#include <iostream>

void VerySatisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now VerySatisfied" << std::endl;
}


void VerySatisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer VerySatisfied" << std::endl;
}

std::string VerySatisfied::getCurrentSatisfactionLevel()
{
    return "Very Satisfied";
}