#ifndef PUBLICSERVICE_H
#define PUBLICSERVICE_H

#include "Utility.h"

class PublicService : public Utility {
private:
    std::string serviceType;
    float funding;

public:
    virtual void provideService();
};

#endif  // PUBLICSERVICE_H