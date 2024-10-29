#include "Satisfied.h"
#include "VerySatisfied.h"
#include "Neutral.h"

#include <iostream>

void Satisfied::enterState()
{
    std::cout << "Citizen Satisfaction Level is now Satisfied";
}


void Satisfied::exitState()
{
    std::cout << "Citizen Satisfaction Level is no longer Satisfied";
}

void Satisfied::nextState(Citizen* citizen)
{
    citizen->setState(new VerySatisfied());
}
        
void Satisfied::prevState(Citizen* citizen)
{
    citizen->setState(new Neutral());
}

std::string Satisfied::getCurrentSatisfactionLevel()
{
    return "Satisfied";
}