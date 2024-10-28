#ifndef RETRIEVETAX_H
#define RETRIEVETAX_H

#include "Building.h"
#include <list>

class RetrieveTax
{
private:
    
public:
    /// @brief Algorithm to collect tax
    /// @param buildings 
    /// @return float
    virtual float CollectTax(std::list<Building*> buildings) = 0;
};


#endif // RETRIEVETAX_H