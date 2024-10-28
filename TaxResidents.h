#ifndef TAXRESIDENTS_H
#define TAXRESIDENTS_H

#include "RetrieveTax.h"

class TaxResidents : public RetrieveTax
{
private:
    
public:
    /// @brief Algorithm to collect tax
    /// @param buildings 
    /// @return float
    float CollectTax(std::list<Building*> buildings);
};


#endif // TAXRESIDENTS_H