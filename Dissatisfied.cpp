#include "Dissatisfied.h"

#include <iostream>

void Dissatisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Dissatisfied";
}


void Dissatisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Dissatisfied";
}

void Dissatisfied::nextState(Citizen* citizen)
{
    citizen->setSatisfactionLevel(new Neutral());
}
        
void Dissatisfied::prevState(Citizen* citizen)
{
    citizen->setSatisfactionLevel(new VeryDissatisfied());
}

std::string Dissatisfied::getCurrentSatisfactionLevel()
{
    return "Dissatisfied";
}