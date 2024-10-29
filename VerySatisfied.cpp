#include "VerySatisfied.h"
#include "Satisfied.h"

#include <iostream>

void VerySatisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now VerySatisfied";
}


void VerySatisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer VerySatisfied";
}

void VerySatisfied::nextState(Citizen* citizen)
{
    std::cout << "Citizen Satisfaction Level is Very Satisfied";
    
}
        
void VerySatisfied::prevState(Citizen* citizen)
{
    citizen->setState(new Satisfied());
}

std::string VerySatisfied::getCurrentSatisfactionLevel()
{
    return "Very Satisfied";
}