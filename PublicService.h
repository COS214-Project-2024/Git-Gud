#ifndef PUBLICSERVICE_H
#define PUBLICSERVICE_H

#include "Utility.h"
#include <string>

class PublicService: public Utility
{
private:

public:
    virtual void provideService() = 0;
};

#endif // PUBLICSERVICE_H