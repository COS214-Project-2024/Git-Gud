#ifndef DISSATISFIED_H
#define DISSATISFIED_H

#include "SatisfactionLevel.h"

class Dissatisfied : public SatisfactionLevel
{
private:
    
public:
    Dissatisfied(){taxReturn = 0.8;};
};


#endif // DISSATISFIED_H