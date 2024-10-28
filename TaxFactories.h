#ifndef TAXFACTORIES_H
#define TAXFACTORIES_H

#include "RetrieveTax.h"

class TaxFactories : public RetrieveTax
{
private:
    
public:
    /// @brief Algorithm to collect tax
    /// @param buildings 
    /// @return float
    float CollectTax(std::list<Building*> buildings);
};


#endif // TAXFACTORIES_H