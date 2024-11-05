#include "VeryDissatisfied.h"

#include <iostream>

void VeryDissatisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Very Dissatisfied" << std::endl;
}


void VeryDissatisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Very Dissatisfied" << std::endl;
}

std::string VeryDissatisfied::getCurrentSatisfactionLevel()
{
    return "Very Dissatisfied";
}