#include "Dissatisfied.h"
#include "Neutral.h"
#include "VeryDissatisfied.h"

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
    citizen->setState(new Neutral());
}
        
void Dissatisfied::prevState(Citizen* citizen)
{
    citizen->setState(new VeryDissatisfied());
}

std::string Dissatisfied::getCurrentSatisfactionLevel()
{
    return "Dissatisfied";
}