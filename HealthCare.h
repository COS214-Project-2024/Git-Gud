#ifndef HEALTHCARE_H
#define HEALTHCARE_H

#include "PublicService.h"

class HealthCare : public PublicService {
public:
    
    HealthCare(int capacity, int maintenanceCost) : PublicService(capacity, maintenanceCost, "HealthCare", 100000){};
    virtual ~HealthCare() = default;
    void callObserver() override;

};

#endif  // HEALTHCARE_H