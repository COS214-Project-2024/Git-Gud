#ifndef TAXCOMMERCIAL_H
#define TAXCOMMERCIAL_H

#include "RetrieveTax.h"

class TaxCommercial : public RetrieveTax
{
private:
    
public:
    /// @brief Algorithm to collect tax
    /// @param buildings 
    /// @return float
    float CollectTax(std::list<Building*> buildings);
};


#endif // TAXCOMMERCIAL_H