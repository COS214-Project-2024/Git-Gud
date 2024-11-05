#ifndef PUBLICSERVICE_H
#define PUBLICSERVICE_H

#include "Utility.h"

class PublicService : public Utility {

    private:
        std::string serviceType;
        int fund;

    public:
        PublicService(int capacity, int maintenanceCost, std::string publicType, int funding) : Utility("PublicService", capacity, maintenanceCost), serviceType(publicType), fund(funding){}
        virtual ~PublicService() = default;
        
};

#endif  // PUBLICSERVICE_H