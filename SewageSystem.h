#ifndef SEWAGE_SYSTEM_H
#define SEWAGE_SYSTEM_H

#include "Utility.h"

class SewageSystem : public Utility
{
private:

public:
    void provideService() override;
};


#endif // SEWAGE_SYSTEM_H