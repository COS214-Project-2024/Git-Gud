#include "Satisfied.h"

#include <iostream>

void Satisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Satisfied" << std::endl;
}


void Satisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Satisfied" << std::endl;
}

std::string Satisfied::getCurrentSatisfactionLevel()
{
    return "Satisfied";
}