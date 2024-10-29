#include "VeryDissatisfied.h"
#include "Dissatisfied.h"

#include <iostream>

void VeryDissatisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Very Dissatisfied";
}


void VeryDissatisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Very Dissatisfied";
}

void VeryDissatisfied::nextState(Citizen* citizen)
{
    citizen->setState(new Dissatisfied());
}
        
void VeryDissatisfied::prevState(Citizen* citizen)
{
    std::cout << "Citizen Satisfaction Level is Very Dissatisfied";
}

std::string VeryDissatisfied::getCurrentSatisfactionLevel()
{
    return "Very Dissatisfied";
}