#include "Neutral.h"

#include <iostream>

void Neutral::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Neutral" << std::endl;
}


void Neutral::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Neutral" << std::endl;
}

std::string Neutral::getCurrentSatisfactionLevel()
{
    return "Neutral";
}