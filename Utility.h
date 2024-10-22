#ifndef UTILITY_H
#define UTILITY_H

#include <String>

class Utility
{
private:
    std::string utilityType;
    int capacity;
    int maintenanceCost;
public:
    virtual void provideService() = 0;
};


#endif // UTILITY_H