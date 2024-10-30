#include "Neutral.h"

#include <iostream>

void Neutral::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Neutral";
}


void Neutral::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Neutral";
}

void Neutral::nextState(Citizen* citizen)
{
    citizen->setSatisfactionLevel(new Satisfied());
}
        
void Neutral::prevState(Citizen* citizen)
{
    citizen->setSatisfactionLevel(new Dissatisfied());
}

std::string Neutral::getCurrentSatisfactionLevel()
{
    return "Neutral";
}